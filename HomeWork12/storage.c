#include <limits.h>
#include "storage.h"
#include <stdio.h>

struct ProtectedStorage{
    TempData*   data_ptr;       //это будет указатель на стартовую ячейку массива, от которой начинать считать
    uint16_t    size;           //ну и количество данных, необходимых для расчёта
    uint16_t    capacity;       //счётчик оставшегося места
};

//---------------------------------------ФУНКЦИИ ИЗМЕНЕНИЯ ХРАНИЛИЩА-----------------------------------------------

/*Для защищённой работы с массивом данных, создадим его приватно внутри функции 
и отдавать будем в виде указателя без раскрытия содержимого*/
ProtectedStorage* create_storage(void){
    static TempData data_storage[STORAGE_SIZE];
    static ProtectedStorage storage = {data_storage, STORAGE_SIZE, 0};
    return &storage;
}

ProcResult push_to_storage(ProtectedStorage* storage, TempData data){
    
    /*
        ЛОГИКА:
        1. Проверяем что не вышли за границу допустимых индексов
        2. Проходим по списку и ищем первую запись, которая по дате выше нашей
        3. Если дошли до конца списка и ничего не нашли, то вставляем в хвост хранилища нашу запись
        4. Если нашли такую запись, то перемещаем все записи от текущей и выше наверх и вставляем нашу
        5. Инкрементируем счётчик хранилища
    */

    //Возвращаем ошибку если хранилище уже заполнено
    if(storage->capacity + 1 > storage->size){
        return FAIL;
    }

    //Забираем указатель на массив данных и переходим к нужному индексу
    TempData* cur_data = storage->data_ptr;
    uint16_t cur_idx = 0;

    //проверяем, есть ли дата записи, большая чем новя
    while(is_date_bigger(cur_data, &data) && (cur_idx < storage->capacity)){
        cur_idx++;
        cur_data++;
    }

    //Если не дошли до конца массива, то перебрасываем все данные от текущей до конца массива на 1 адрес вверх
    if(cur_idx != storage->capacity){ 
        for(TempData* cur_ptr = (storage->data_ptr) + storage->capacity; cur_ptr >= cur_data; cur_ptr--){
            *(cur_ptr + 1) = *cur_ptr;
        }
    }
    *cur_data = data;   //Копируем новые данные 

    //Инкрементируем значение числа записей для внесения новой
    storage->capacity++;

    return SUCSESS;
}

ProcResult pull_from_storage(ProtectedStorage* storage){
    //Возвращаем ошибку если хранилище уже пустое
    if(storage -> capacity == 0){
        return FAIL;
    } 
    storage -> capacity--;
    return SUCSESS;
}

ProcResult delete_entry(ProtectedStorage* storage, Date date, Time time){
    TempData* data_ptr = storage->data_ptr;

    for(uint16_t idx; idx < storage->capacity; idx++){  //ищем запись за требуемую дату
        if(is_same_dates(data_ptr + idx, date, time)){  //если находим
            for(int16_t i = idx; i < storage->capacity - 1; i++){
                *(data_ptr + i) = *(data_ptr + i + 1);          //смещаем все записи на 1 ниже
            }
            storage->capacity--;
            return SUCSESS;
        }
    }
    
    return FAIL;
}

//-------------------------------------------ФУНКЦИИ ПОИСКА--------------------------------------------


DataRange find_in_year(const ProtectedStorage* storage, Date date){    //Вернёт область, где хранятся все записи за год
    /*
        текущее тз подразумевает данные за коркретный год, поэтому достаточно возврата диапазона всего массива
        если в дальнейшем массив будет расширен на несколько лет, то можно будет просто дописать текущую функцию
    */
    //если нет запрашиваемого года, то вернём нулевой размер диапазона
    if(date.year != storage->data_ptr->year){
        return (DataRange){storage->data_ptr, 0};
    }
    return (DataRange){storage->data_ptr, storage->capacity};   //пока в виде заглушки возвращает весь массив
} 

DataRange find_in_month(const ProtectedStorage* storage, Date date){   //Вернёт область, где хранятся все записи за месяц
    /*
        текущее тз подразумевает обработку данных всего за один год
        если в дальнейшем запросы будут касаться нескольких лет, то достаточно переписать только эту функцию    
    */

    TempData* cur_data = storage->data_ptr;
    uint16_t cur_idx = 0;

    //проходим данные, которые не соответствуют нашему диапазону
    while((date.month != cur_data->month) && (cur_idx < storage->capacity)){
        cur_data++;
        cur_idx++;
    }

    //Если дошли до конца массива, то вернём нулевой размер диапазона
    if(cur_idx == storage->capacity){
        return (DataRange){storage->data_ptr, 0};
    }

    //запоминаем индекс массива и указатель на старт области, от которого начинается наш диапазон
    uint16_t start_idx = cur_idx;
    TempData* start_ptr = cur_data;

    //далее отсчитываем число записей, соответствующих нашему диапазону
    while((date.month == cur_data->month) && (cur_idx < storage->capacity)){
        cur_data++;
        cur_idx++;
    }

    return (DataRange){start_ptr, cur_idx - start_idx};   //пока в виде заглушки возвращает весь массив
}

//--------------------------------------------ФУНКЦИИ ВЫВОДА--------------------------------------------------


static void print_one_entry(const TempData* d_ptr){
    printf("%d.%d.%d\t%d:%d\t%d\n",
            d_ptr->year,
            d_ptr->month,
            d_ptr->day,
            d_ptr->hour,
            d_ptr->min,
            d_ptr->temp
        );
}

int8_t read_temp_from_storage(const DataRange* data_ptr, uint16_t index){
    return ((data_ptr->data_ptr) + index)->temp;
}

uint16_t get_the_year(const ProtectedStorage* storage){
    return storage->data_ptr->year;
}

uint16_t current_capacity(const ProtectedStorage* storage){
    return storage->capacity;
}

void print_all_by_date(const ProtectedStorage* storage, SortOrder ord){
    printf("--------------------------------\n");
    printf("Temperature data ranged by date,");
    //по умолчанию хранилище автоматически сортируется по дате по возрастанию, поэтому выводим данные просто по порядку
    if(ord == ASCENDING){
        printf(" by ascending:\n");
        printf("Date\t\tTime\tTemp\n");
        for(int i = 0; i < storage->capacity; i++){
            print_one_entry(storage->data_ptr + i);
        }
    }
    else{
        printf(" by descending:\n");
        printf("Date\t\tTime\tTemp\n");
        for(int i = storage->capacity - 1; i >= 0; i--){
            print_one_entry(storage->data_ptr + i);
        }
    }
    
    printf("--------------------------------\n");
}

void print_all_by_temp(const ProtectedStorage* storage, SortOrder ord){
    printf("--------------------------------\n");
    printf("Temperature data ranged by temperature,");

    /*
        ЛОГИКА:
        1. Создаём экстремум, то есть минимальное или максимальное значение
        2. Проходим по всей заполненной части массива число раз, равное числу записей в массиве
        3. Ищем по всему массиву, значение, максимально близкое к текущему, 
        в зависимости от порядка сортировки, которое меньше или больше заданного
        4. Если нашли такое же, то проверяем, та же ли эта запись, если та же или предыдущая, то игнорируем
    */

    int8_t cur_t = 0;
    TempData* min_line = NULL;
    if(ord == ASCENDING){
        printf(" by ascending:\n");
        printf("Date\t\tTime\tTemp\n");
        cur_t = INT8_MIN;
    }
    else{
        printf(" by descending:\n");
        printf("Date\t\tTime\tTemp\n");
        cur_t = INT8_MAX;
    }
    for(int i = 0; i < storage->capacity; i++){
        int16_t min_dist = INT16_MAX;
        TempData* cur_min_line = NULL;
        for(int j = 0; j < storage->capacity; j++){
            TempData* tmp_line = storage->data_ptr + j;
            int16_t cur_dist = find_dist(cur_t, tmp_line->temp, ord);
            if(cur_dist < 0){   //пропуск если расстояние "не соответствует направлению сортировки"
                continue;
            }
            if(cur_dist == 0){  //если значение минимума совпадает
                if(tmp_line > min_line){    //но запись более поздняя
                    cur_min_line = tmp_line;    //обновляем указатель на запись
                    break;                      //вылетаем из цикла
                }
                else{   //пропуск, если это та же запись или младше
                    continue;
                }
            }
            if((min_dist == cur_dist) && (tmp_line > min_line)){    //Пропуск, если запись старше по дате
                continue;
            }
            if(min_dist > cur_dist){    //если дистанция до значения минимальна
                cur_min_line = tmp_line;    //обновляем указатель на данные, где содержится это значение
                min_dist = cur_dist;        //обновляем минимальное значение дистанции
            }
        }
        min_line = cur_min_line;
        print_one_entry(min_line);
        cur_t = min_line->temp;     //под конец прохода по записям обновляем опорное значение 
    }
    printf("--------------------------------\n");
}



//--------------------------------------ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ--------------------------------

static int16_t find_dist(const int8_t ref, const int8_t checked, const SortOrder ord){
    return -ord * (ref - checked);
}

static uint8_t is_date_bigger(const TempData* ref, const TempData* checked){
    //сравниваем день, месяц и год
    uint32_t ref_date = (ref->year << 16) + (ref->month << 8) + ref->day;
    uint32_t checked_date = (checked->year << 16) + (checked->month << 8) + checked->day;
    if(ref_date != checked_date){
        return (ref_date < checked_date);
    }
    //если даты совпадают, то сравниваем по времени
    uint16_t ref_time = (ref->hour << 8) + ref->min;
    uint16_t checked_time = (checked->hour << 8) + checked->min;
    if(ref_time != checked_time){
        return (ref_time < checked_time);
    }
    return 0;
}

static uint8_t is_same_dates(const TempData* ref_data, const Date checked_date, const Time checked_time){
    uint32_t ref_date = (ref_data->year << 16) + (ref_data->month << 8) + ref_data->day;
    uint32_t ch_date = (checked_date.year << 16) + (checked_date.month << 8) + checked_date.day;
    uint16_t ref_time = (ref_data->hour << 8) + ref_data->min;
    uint16_t ch_time = (checked_time.hour << 8) + checked_time.min;

    return ((ref_date == ch_date) && (ref_time == ch_time));
}
