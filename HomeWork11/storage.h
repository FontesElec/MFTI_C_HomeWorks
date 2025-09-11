#include <stdint.h>

//Defines
#define STORAGE_SIZE 20

//Typedefs
//Собираем структуры без раскрытия полей (opaque type)
typedef struct TempData TempData;
typedef struct ProtectedStorage ProtectedStorage;

//Открытые типы данных для работы с внешними файлами
typedef struct{
    TempData*       data_ptr;
    const uint16_t  num_of_records;
} DataRange;


typedef enum{
    SUCSESS,
    FAIL
} ProcResult;

/*
    Структуры, обисаные ниже нужны именно для внешнего взаимодействия, 
    т.к. внтруннее содержимое самого хранилища скрыто от остальных файлов.
    Структура самого хранилища описана в storage.c
*/
typedef struct{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} Date;

typedef struct{
    uint8_t hour;
    uint8_t min;
} Time;

typedef struct{
    Date date;
    Time time;
    int8_t temperature;
} Data;

//FunctionPrototypes
/*
    ProtectedStorage* create_storage(void) создаёт хранилище фиксированного размера (задано с помощью STORAGE_SIZE). 
    Возвращает непрозрачный указатель на хранилище
*/
ProtectedStorage*  create_storage(void);

/*
    ProcResult  push_to_storage(ProtectedStorage* storage, Data data);
    Добавляет запись в хранилище.
    Принимает на вход указатель на заполняемое хранилище и новые данные.
    Возвращает результат работы
*/
ProcResult push_to_storage(ProtectedStorage* storage, Data data);

/*
    ProcResult  pull_from_storage(ProtectedStorage* storage);
    Стирает последнюю запись из хранилища.
    Принимает на вход указатель на изменяемое хранилище.
    Возвращает результат работы
*/
ProcResult pull_from_storage(ProtectedStorage* storage);

/*
    int8_t  read_temp_from_storage(const DataRange* data_ptr, uint16_t index);
    Принимает указатель на область данных и номер записи, которая необходима.
    Возвращает значение температуры.
*/
int8_t read_temp_from_storage(const DataRange* data_ptr, uint16_t index);

/*
    DataRange find_in_year(const ProtectedStorage* storage, Date date);
    Принимает указатель на хранилище и дату.
    Возвращает область данных, которая соответствует запрашиваемому году
*/
DataRange find_in_year(const ProtectedStorage* storage, Date date);

/*
    DataRange find_in_month(const ProtectedStorage* storage, Date date);
    Принимает указатель на хранилище и дату.
    Возвращает область данных, которая соответствует запрашиваемому месяцу
*/
DataRange find_in_month(const ProtectedStorage* storage, Date date);
