#include <limits.h>
#include <stdio.h>
#include "temp_api.h"

#define TEST

int main(void) {

    //Создаём хранилище
    ProtectedStorage* my_storage = create_storage();

    //В дальнейшем, в зависимости от ключа поиска, будем присваивать свой вариант поиска диапазона: за год, или за месяц
    DataRange (*range_finder)(const ProtectedStorage* storage, Date date) =  find_in_year;

    #ifdef TEST
    
        push_to_storage(my_storage, (Data){(Date){2011,2,3}, (Time){12,23}, 13});
        push_to_storage(my_storage, (Data){(Date){2011,2,7}, (Time){12,23}, 16});
        push_to_storage(my_storage, (Data){(Date){2011,2,9}, (Time){12,23}, 17});
        push_to_storage(my_storage, (Data){(Date){2011,2,15}, (Time){12,23}, 11});
        push_to_storage(my_storage, (Data){(Date){2011,2,30}, (Time){12,23}, 24});
        push_to_storage(my_storage, (Data){(Date){2011,3,3}, (Time){12,23}, 12});
        push_to_storage(my_storage, (Data){(Date){2011,3,14}, (Time){12,23}, 10});
        push_to_storage(my_storage, (Data){(Date){2011,3,19}, (Time){12,23}, 5});
        push_to_storage(my_storage, (Data){(Date){2011,3,26}, (Time){12,23}, 0});
        push_to_storage(my_storage, (Data){(Date){2011,4,3}, (Time){12,23}, -3});
        push_to_storage(my_storage, (Data){(Date){2011,4,13}, (Time){12,23}, -7});
        push_to_storage(my_storage, (Data){(Date){2011,4,19}, (Time){12,23}, -10});
        push_to_storage(my_storage, (Data){(Date){2011,4,24}, (Time){12,23}, -28});
        push_to_storage(my_storage, (Data){(Date){2011,4,30}, (Time){12,23}, -13});
        push_to_storage(my_storage, (Data){(Date){2011,5,3}, (Time){12,23}, -5});
        push_to_storage(my_storage, (Data){(Date){2011,5,13}, (Time){12,23}, -1});
        push_to_storage(my_storage, (Data){(Date){2011,5,19}, (Time){12,23}, 0});
        push_to_storage(my_storage, (Data){(Date){2011,5,26}, (Time){12,23}, 12});
        push_to_storage(my_storage, (Data){(Date){2011,6,3}, (Time){12,23}, 16});
        push_to_storage(my_storage, (Data){(Date){2011,6,9}, (Time){12,23}, 19});
        
    #endif
    
    //Запускаем поиск области, в которой будем искать данные
    DataRange range = range_finder(my_storage, (Date){2011,0,0});

    
    int8_t min = min_temp(&range);
    int8_t max = max_temp(&range);
    double avg = avg_temp(&range);

    printf("Minimal temeperature %d, maximal temperature %d, average temperature %0.3f", min, max, avg);

    return 0;
}