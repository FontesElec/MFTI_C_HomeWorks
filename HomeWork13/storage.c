#include <limits.h>
#include "storage.h"
#include <stdio.h>
#include <stdlib.h>

//Создаём двухсвязный список
struct StorageNode{
    TempData data;             //данные
    StorageNode* prev;         //указатель на предыдущий узел
    StorageNode* next;         //указатель на следующий узел
};

struct ProtectedStorage{
    StorageNode*   head;       //указатель на первый узел
    StorageNode*   tail;       //указатель на хвостовой узел
};

//--------------------------------------ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ----------------------------------

/**
*   Считает расстояние от значения ref до значение checked, знак выходного значения будет определяться значением ord
*   @param ref      Значение, от которого считаем расстояние
*   @param checked  Значение, до которого считаем расстояние
*   @param ord      Определение положительного направления при вычислении расстояния
*   @return Расстояние от ref до checked с учётом направления ord
*/
static int16_t find_dist(const int8_t ref, const int8_t checked, const SortOrder ord);

/**
*   Выдаёт лог 1 если дата, содержащаяся в checked больше, чем содержащаяся в ref
*   @param ref      Указатель на базовую ячейку, относительно которой проверяем
*   @param checked  Указатель на проверяемую ячейку
*   @return Вернёт 1 если дата в checked больше, иначе 0
*/
static uint8_t is_date_bigger(const TempData* ref, const TempData* checked);

/**
*   Сравнивает дату и время из записи и запрашиваемую
*   @param ref_data     Указатель на запись в хранилище
*   @param checked_date Запрашиваемая дата
*   @param checked_time Запрашиваемое время
*   @return Вернёт 1 если дата и время совпадают с датой и временем из записи, иначе 0
*/
static uint8_t is_same_dates(const TempData* ref_data, const Date checked_date, const Time checked_time);

/**
*   Выводит одну строку данных
*   @param d_ptr    Указатель на ячейку хранилища
*/
static void print_one_entry(const TempData* d_ptr);

//---------------------------------------ФУНКЦИИ ИЗМЕНЕНИЯ ХРАНИЛИЩА-----------------------------------------------

/*Для защищённой работы с массивом данных, создадим его приватно внутри функции 
и отдавать будем в виде указателя без раскрытия содержимого*/
ProtectedStorage* create_storage(void){
    static ProtectedStorage storage = {NULL,NULL};
    return &storage;
}

ProcResult push_to_storage(ProtectedStorage* storage, TempData data){
    /*
        ЛОГИКА:
        1. Создаём узел, проверяем успешность создания, копируем данные
        2. Проходим по узлам хранилища, пока не упрёмся в null или пока не найдём дату, старше вносимой
        3. Если список был пуст, то вставляем новую запись, указатели на начало и конец списка указывают на новую запись
        4. Если список имеет записи, то проходим по списку в поиске либо конца, либо даты, старше новой, вставляем новый узел
    */

    //Выделяем место под новый узел
    StorageNode* new_node = (StorageNode*)malloc(sizeof(StorageNode));
    //Проверка на успешность выделения памяти
    if(!new_node){
        printf("Failed to memory allocation\n");
        return FAIL;
    }
    //Копируем информацию
    new_node->data = data;
    
    StorageNode* current_node = storage->head;
    //Если список пуст
    if(!current_node){
        //Привязываем узел к хранилищу
        storage->head = storage->tail = new_node;
        //Обнуляем указатели в первой записи
        new_node->prev = new_node->next = NULL;
        return SUCSESS;
    }
    //Если список не пуст, проходим по записям, пока не дойдём до нулевого указателя, или до большей даты
    while((current_node) && is_date_bigger(&(current_node->data), &data)){
        current_node = current_node->next;
    }
    //Если указатель не нулевой, то вставка посреди списка
    if(current_node){
        //Так как текущий узел содержит дату, старше, чем в новой записи, то вставка ПЕРЕД текущим узлом
        //Поэтому проверяем, можем ли мы подняться на узел выше
        if(current_node->prev){
            //Привязываем новый узел к текущему
            new_node->next = current_node;                          //A->B и A<-B, теперь A->B и N->B и A<-B
            //Поднимаемся выше
            current_node = current_node->prev;                      //теперь находимся в A
            //Теперь нужно из-под нового узла можно в старом обновить привязку
            new_node->next->prev = new_node;                        //теперь A->B, N->B, N<-B
            //Привязываем к младшему узле новый
            current_node->next = new_node;                          //теперь A->N, N->B, N<-B
            //И наоборот
            new_node->prev = current_node;                          //A->N, A<-N, N->B, N<-B
            return SUCSESS;
        }
        //Если узел первый в списке, то вставка в начало
        else{
            //обновляем головной узел
            storage->head = new_node;
            //привязка текущего узла к новому
            current_node->prev = new_node;
            //привязка нового узла к текущему
            new_node->next = current_node;
            //так как новый узел в голове списка, то перед ним узлов нет
            new_node->prev = NULL;
            return SUCSESS;
        }
    }
    //Если указатель пуст, то вставка в хвост списка
    //переходим в текущий хвостовой узел
    current_node = storage->tail;
    //меняем указатель хвостового узла на новый 
    storage->tail = new_node;
    //привязываем новый узел к текущему
    current_node->next = new_node;
    //привязываем новый узел к текущему
    new_node->prev = current_node;
    //обозначаем завершение списка
    new_node->next = NULL;

    return SUCSESS;
}

ProcResult pull_from_storage(ProtectedStorage* storage){
    //Возвращаем ошибку если хранилище уже пустое
    if(storage->head == NULL){
        return FAIL;
    } 
    //Забираем указатель на текущий хвостовой узел
    StorageNode* node_on_delete = storage->tail;
    //Забираем указатель на узел, идущий перед хвостовым
    StorageNode* new_tail = node_on_delete->prev;
    //Если узел был последним, то new_tail будет нулевым
    if(new_tail == NULL){
        storage->head = NULL;
    }
    //иначе, отвязываем удаляемый узел от списка
    else{
        new_tail->next = NULL;
        storage->tail = new_tail;
    }
    //стираем узел
    free(node_on_delete);
    node_on_delete = NULL;
    return SUCSESS;
}

ProcResult delete_entry(ProtectedStorage* storage, Date date, Time time){
    StorageNode* cur_node = storage->head;
    StorageNode* matched = NULL;
    while(cur_node){
        if(is_same_dates(&(cur_node->data), date, time)){
            matched = cur_node;
            break;
        }
        cur_node = cur_node->next;
    }

    if(matched == NULL){
        printf("The entry with such date and time was not found\n");
        return FAIL;
    }

    //определяем узлы, расположенные перед и за удаляемым
    StorageNode* prev_node = matched->prev;
    StorageNode* next_node = matched->next;

    //определяем, расположены ли мы в хвосте или в начале списка
    if(prev_node == NULL){  //если в начале
        storage->head = next_node;
        if(next_node){
            next_node->prev = NULL;
        }
    }
    if(next_node == NULL){  //если в конце списка
        storage->tail = prev_node;
        if(prev_node){
            prev_node->next = NULL;
        }
    }
    if(next_node && prev_node){ //если где-то посреди
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    
    free(matched);
    matched = NULL;

    return SUCSESS;
}

//-------------------------------------------ФУНКЦИИ ПОИСКА--------------------------------------------


DataRange find_in_year(const ProtectedStorage* storage, Date date){    //Вернёт область, где хранятся все записи за год
    /*
        текущее тз подразумевает данные за коркретный год, поэтому достаточно возврата диапазона всего массива
        если в дальнейшем массив будет расширен на несколько лет, то можно будет просто дописать текущую функцию
    */
    if(storage->head == NULL){
        printf("Error: this storage is empty\n");
        return (DataRange){NULL,0};
    }
    //если нет запрашиваемого года, то вернём нулевой размер диапазона
    if(date.year != storage->head->data.year){
        printf("Error: nothing found\n");
        return (DataRange){storage->head, 0};
    }
    uint16_t cntr = 0;
    StorageNode* cur_node = storage->head;
    while(cur_node){
        cur_node = cur_node->next;
        cntr++;
    }
    return (DataRange){storage->head, cntr};   //пока в виде заглушки возвращает весь массив (для текущего тз)
} 

DataRange find_in_month(const ProtectedStorage* storage, Date date){   //Вернёт область, где хранятся все записи за месяц
    /*
        текущее тз подразумевает обработку данных всего за один год
        если в дальнейшем запросы будут касаться нескольких лет, то достаточно переписать только эту функцию    
    */
    if(storage->head == NULL){
        printf("Error: this storage is empty\n");
        return (DataRange){NULL, 0};
    }
    StorageNode* cur_node = storage->head;
    uint16_t entrys_cntr = 0;

    //проходим данные, которые не соответствуют нашему диапазону
    while((cur_node) && (cur_node->data.month != date.month)){
        cur_node = cur_node->next;
    }

    //Если дошли до конца массива, то вернём нулевой размер диапазона
    if(cur_node == NULL){
        printf("Error: nothing found\n");
        return (DataRange){storage->head, 0};
    }

    //Запоминаем стартовую запись в области
    StorageNode* start_node = cur_node;

    //далее отсчитываем число записей, соответствующих нашему диапазону
    while((cur_node) && (cur_node->data.month == date.month)){
        entrys_cntr++;
        cur_node = cur_node->next;
    }

    return (DataRange){start_node, entrys_cntr};  
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

int8_t read_temp_from_storage(const DataRange* node_ptr, uint16_t index){
    const StorageNode* cur_node = node_ptr->data_ptr;
    for(int i = 0; i < index; i++){
        cur_node = cur_node->next;
    }
    return cur_node->data.temp;
}

uint16_t get_the_year(const ProtectedStorage* storage){
    return storage->head->data.year;
}

void print_all_by_date(const ProtectedStorage* storage, SortOrder ord){
    printf("--------------------------------\n");
    printf("Temperature data ranged by date,");
    //по умолчанию хранилище автоматически сортируется по дате по возрастанию, поэтому выводим данные просто по порядку
    if(ord == ASCENDING){
        printf(" by ascending:\n");
        printf("Date\t\tTime\tTemp\n");
        StorageNode* current_node = storage->head;
        while(current_node){
            print_one_entry(&(current_node->data));
            current_node = current_node->next;
        }
    }
    else{
        printf(" by descending:\n");
        printf("Date\t\tTime\tTemp\n");
        StorageNode* current_node = storage->tail;
        while(current_node){
            print_one_entry(&(current_node->data));
            current_node = current_node->prev;
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
        2. Проходим по списку в прмом направлении
        3. Ищем по всему массиву, значение, максимально близкое к текущему, 
        в зависимости от порядка сортировки, которое меньше или больше заданного
        4. Проходим ещё раз по списку и печатаем все значения текущего минимума
        5. Минимум становится базовой точкой отсчёта, от него вновь считаем все дистанции
        6. Условием завершения работы будет отсутствие нового минимума дистанции
    */

    int8_t cur_t = 0;
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

    uint8_t sort_processing = 1;
    while(sort_processing){
        
        int16_t min_dist = INT16_MAX;

        StorageNode* cur_min_node = storage->head;
        StorageNode* tmp_node = storage->head;
        //сбрасываем флаг хода обработки, если будет найден новый минимум, флаг будет взведён вновь
        sort_processing = 0;

        while(tmp_node){
            int16_t cur_dist = find_dist(cur_t, tmp_node->data.temp, ord);
            if(cur_dist <= 0){   //пропуск если расстояние "не соответствует направлению сортировки" или уже минимальное
                tmp_node = tmp_node->next;
                continue;  
            }
            if(min_dist > cur_dist){        //если дистанция до значения минимальна
                sort_processing = 1;        //взводим флаг обработки
                min_dist = cur_dist;        //обновляем минимальное значение дистанции
                cur_min_node = tmp_node;    //сохраняем указатель на минимальный узел
            }
            tmp_node = tmp_node->next;
        }

        //если найден новый минимум, проходим в поиске всех одинаковых записей
        if(sort_processing){
            tmp_node = cur_min_node;
            while(tmp_node){
                if(cur_min_node->data.temp == tmp_node->data.temp){
                    print_one_entry(&(tmp_node->data));
                }
                tmp_node = tmp_node->next;
            }
            cur_t = cur_min_node->data.temp;
        }
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


