#include "temp_api.h"
#include "limits.h"

/*  Расчёт параметров независим от его вариаций, пусть это год или месяц, с точки зрения приложения это будет
    выглядеть в виде различий диапазона расчёта.
*/
int8_t min_temp(const DataRange* range){
    int8_t min_t = _I8_MAX;
    for(uint16_t i = 0; i < range->num_of_records; i++){
        if(read_temp_from_storage(range,i) < min_t){
            min_t = read_temp_from_storage(range,i);
        }
    }
    return min_t;
}

int8_t max_temp(const DataRange* range){
    int8_t max_t = _I8_MIN;
    for(uint16_t i = 0; i < range->num_of_records; i++){
        if(read_temp_from_storage(range,i) > max_t){
            max_t = read_temp_from_storage(range,i);
        }
    }
    return max_t;
}

double avg_temp(const DataRange*  range){
    double avg_t = 0;
    for(uint16_t i = 0; i < range->num_of_records; i++){
        avg_t += read_temp_from_storage(range,i);
    }
    avg_t /= (double)(range->num_of_records);
    return avg_t;
}