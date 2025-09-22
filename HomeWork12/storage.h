#include <stdint.h>

//--------------------------Defines-----------------------------
#define STORAGE_SIZE 20

//-------------------------Typedefs-----------------------------
//Собираем структуру без раскрытия полей (opaque type)

//Cтруктура хранилища данных
typedef struct ProtectedStorage ProtectedStorage;   

//Открытые типы данных для работы с внешними файлами

//Базовая структура хранения данных
typedef struct{                                     
    uint16_t    year;
    uint8_t     month;
    uint8_t     day;
    uint8_t     hour;
    uint8_t     min;
    int8_t      temp;
} TempData;

//Область данных (указатель на начало хранилища и число записей)
typedef struct{
    const TempData*       data_ptr;
    const uint16_t  num_of_records;
} DataRange;

//Дата для работы с поиском записей
typedef struct{
    uint16_t year;
    uint8_t month;
    uint8_t day;
} Date;

//Время, для возможности удаления конкретной записи
typedef struct{
    uint8_t hour;
    uint8_t min;
} Time;

//Результат изменения записей в хранилище
typedef enum{
    SUCSESS,
    FAIL
} ProcResult;

//Порядок сортировки
typedef enum{
    DESCENDING = -1,
    ASCENDING = 1
} SortOrder;

//-------------------------------FunctionPrototypes--------------------------------

//---------------------------------------ФУНКЦИИ ИЗМЕНЕНИЯ ХРАНИЛИЩА------------------------------------------
/**
*   Создаёт хранилище фиксированного размера (задано с помощью STORAGE_SIZE). 
*   @return   Непрозрачный указатель на хранилище
*/
ProtectedStorage*  create_storage(void);

/**
*   Добавляет запись в хранилище.
*   @param storage  Указатель на заполняемое хранилище
*   @param data     Данные, которые должны быть добавлены
*   @return     Результат попытки добавления записи
*/
ProcResult push_to_storage(ProtectedStorage* storage, TempData data);

/**
*   Стирает последнюю запись из хранилища.
*   @param storage  Указатель на изменяемое хранилище
*   @return     Результат попытки удаления записи
*/
ProcResult pull_from_storage(ProtectedStorage* storage);

/**
*   Удаляет запись, соответствующую введённым параметрам
*   @param storage  Указатель на хранилище
*   @param date     Дата удаляемой записи
*   @param time     Время удаляемой записи
*   @return     Результат попытки удаления
*/
ProcResult delete_entry(ProtectedStorage* storage, Date date, Time time);

//-------------------------------------------ФУНКЦИИ ПОИСКА--------------------------------------------

/**
*   Ищет в хранилище область данных, в которой хранятся все записи за требуемый год
*   @param storage  Указатель на хранилище
*   @param date     Запрашиваемая дата
*   @return     Область данных, которая соответствует запрашиваемому году
*/
DataRange find_in_year(const ProtectedStorage* storage, Date date);

/**
*   Ищет в хранилище область данных, в которой хранятся все записи за требуемый месяц
*   @param storage  Указатель на хранилище
*   @param date     Запрашиваемая дата
*   @return     Область данных, которая соответствует запрашиваемому месяцу
*/
DataRange find_in_month(const ProtectedStorage* storage, Date date);

//--------------------------------------------ФУНКЦИИ ВЫВОДА--------------------------------------------

/**
*   Возвращает запрашиваемое значение температуры
*   @param data_ptr Указатель на область данных
*   @param index    Номер записи, которая необходима
    @return     Значение температуры.
*/
int8_t read_temp_from_storage(const DataRange* data_ptr, uint16_t index);

/**
*   Возвращает год, за который лижит статистика в хранилище
*   @param storage Указатель на хранилище
*   @return Год, указанный в первой записи хранилища 
*/
uint16_t get_the_year(const ProtectedStorage* storage);

/**
*   Возвращает число записей в хранилище
*   @param storeage указатель на хранилище
*   @return число записей
*/
uint16_t current_capacity(const ProtectedStorage* storage);


/**
*   Выводит на печать всё содержимое массива, по умолчанию сортировка всегда по дате записи
*   @param storage  Указатель на хранилище
*   @param ord      Порядок сортировки
*/
void print_all_by_date(const ProtectedStorage* storage, SortOrder ord);

/**
*   Выводит на печать всё содержимое массива, отсортированное по температуре
*   @param storage  Указатель на хранилище
*   @param ord      Порядок сортировки
*/
void print_all_by_temp(const ProtectedStorage* storage, SortOrder ord); 

/**
*   Выводит одну строку данных
*   @param d_ptr    Указатель на ячейку хранилища
*/
static void print_one_entry(const TempData* d_ptr);


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