#include "storage.h"

struct TempData{                //базовая структура хранения данных
    uint16_t    year;
    uint8_t     month;
    uint8_t     day;
    uint8_t     hour;
    uint8_t     min;
    int8_t      temp;
};

struct ProtectedStorage{
    TempData*   data_ptr;       //это будет указатель на стартовую ячейку массива, от которой начинать считать
    uint16_t      size;         //ну и колличество данных, необходимых для расчёта
    uint16_t      capacity;     //счётчик оставшегося места
};


//---------------------------------------ФУНКЦИИ ИЗМЕНЕНИЯ ХРАНИЛИЩА-----------------------------------------------

/*Для защищённой работы с массивом данных, создадим его приватно внутри функции 
и отдавать будем в виде указателя без раскрытия содержимого*/
ProtectedStorage* create_storage(void){
    static TempData data_storage[STORAGE_SIZE];
    static ProtectedStorage storage = {data_storage, STORAGE_SIZE, 0};
    return &storage;
}

ProcResult push_to_storage(ProtectedStorage* storage, Data data){
    //Возвращаем ошибку если хранилище уже заполнено
    if(storage->capacity + 1 > storage->size){
        return FAIL;
    }

    //Забираем указатель на массив данных и переходим к нужному индексу
    TempData* new_data = storage->data_ptr + storage->capacity;

    //Необходимость такой переюроски связана с скрытым типом ProtectedStorage
    new_data->year  = data.date.year;
    new_data->month = data.date.month;
    new_data->day   = data.date.day;
    new_data->hour  = data.time.hour;
    new_data->min   = data.time.min;
    new_data->temp  = data.temperature;

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

//-------------------------------------------ФУНКЦИИ ЧТЕНИЯ И ПОИСКА--------------------------------------------

int8_t read_temp_from_storage(const DataRange* data_ptr, uint16_t index){
    return ((data_ptr->data_ptr) + index)->temp;
}

DataRange find_in_year(const ProtectedStorage* storage, Date date){    //Вернёт область, где хранятся все записи за год
    #warning NEED TO WRITE THE FUNCTION IMPLEMENTATION
    return (DataRange){storage->data_ptr, storage->size};   //пока в виде заглушки возвращает весь массив
} 

DataRange find_in_month(const ProtectedStorage* storage, Date date){   //Вернёт область, где хранятся все записи за месяц
    #warning NEED TO WRITE THE FUNCTION IMPLEMENTATION
    return (DataRange){storage->data_ptr, storage->size};   //пока в виде заглушки возвращает весь массив
}