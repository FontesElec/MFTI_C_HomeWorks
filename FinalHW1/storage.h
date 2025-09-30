#include <stdint.h>

//--------------------------Defines-----------------------------
#define STORAGE_SIZE 20

//-------------------------Typedefs-----------------------------

//Cтруктура узла хранилища данных
typedef struct StorageNode StorageNode;

//Структура заголовка двухсвязного списка хранилища данных
typedef struct ProtectedStorage ProtectedStorage;

//Базовая структура хранения данных
typedef struct{                                     
    uint16_t    year;
    uint8_t     month;
    uint8_t     day;
    uint8_t     hour;
    uint8_t     min;
    int8_t      temp;
} TempData;

/**
 * Область данных для поиска(указатель на начало хранилища и число записей)
 * @param data_ptr указатель на StorageNode, с которого начинается поиск
 * @param num_of_records число записей в списке
 */
typedef struct{
    const StorageNode*      data_ptr;
    const uint16_t          num_of_records;
} DataRange;

/**
 * Формат даты
 * @param year
 * @param month
 * @param day
*/
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

/**
 * Результат изменения записей в хранилище
 * @param SUCCESS функция отработала штатно
 * @param FAIL при выполнении программы возникла проблема
 */
typedef enum{
    SUCSESS,
    FAIL
} ProcResult;

/**
 * Порядок сортировки
 * @param DESCENDING запускает сортировку по убыванию
 * @param ASCENDING запускает сортировку по возрастанию
 */ 
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
*   @param node_ptr Указатель на узел с данными
*   @param index    Номер записи, которая необходима
    @return     Значение температуры.
*/
int8_t read_temp_from_storage(const DataRange* node_ptr, uint16_t index);

/**
*   Возвращает год, за который лежит статистика в хранилище
*   @param storage Указатель на хранилище
*   @return Год, указанный в первой записи хранилища 
*/
uint16_t get_the_year(const ProtectedStorage* storage);

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
* Выводит на печать данные за диапазон
* @param range диапазон печати (указатель на начальный узел и число узлов для печати)
*/
void print_in_range(const DataRange* range);

