#include <stdint.h>
#include "storage.h"

//Function prototypes
/*  Расчёт параметров независим от его вариаций, пусть это год или месяц, с точки зрения приложения это будет
    выглядеть в виде различий диапазона расчёта.
*/

/*
    int8_t min_temp(const DataRange* range);
    Принимает диапазон поиска в хранилище данных
    Отдаёт минимальное значение температуры
*/
int8_t min_temp(const DataRange* range);

/*
    int8_t max_temp(const DataRange* range);
    Принимает диапазон поиска в хранилище данных
    Отдаёт максимальное значение температуры
*/
int8_t max_temp(const DataRange* range);

/*
    double avg_temp(const DataRange*  range);
    Принимает диапазон поиска в хранилище данных
    Отдаёт среднее значение температуры за диапазон
*/
double avg_temp(const DataRange*  range);