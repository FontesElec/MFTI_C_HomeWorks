#include "temp_api.h"
#include "limits.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARAMS_READED   6 //сколько параметров будет считано в строке при создании новой записи

//привяжем указатель на хранилище как глобальную переменную, будем определять, открыт ли .csv файл(при этом создаётся хранилище)
static ProtectedStorage* my_storage = NULL; 
//указатель на файл, который будет открыт
static FILE* file = NULL;

ProcResult help_cmd(char* arg){
    (void)arg;
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("COMMAND LIST:\n\n");
    printf("(null)\tif the parameter is empty, the command list will be printed\n");
    printf("-h\t(no parameters) will open command list\n");
    printf("-f\t(filename.csv) will open the file with data\n");
    printf("-y\t(year) will output data on the minimum, maximum, and average temperature for the year\n");
    printf("-m\t(month number) will output data on the minimum, maximum, and average temperature for the month\n");
    printf("-n\t(yyyy.mm.dd;hh:mm;t) will add a new entry to the repository\n");
    printf("-l\t(no parameters) will delete the last entry in the repository\n");
    printf("-d\t(yyyy.mm.dd;hh:mm) will delete a record from storage with a specific date and time\n");
    printf("-t\t(no parameters) will launched demonstration program\n");
    printf("-s\t(ad/dd/at/dt) will output all storage data sorted by:\
            \n\t* ad - ascending date\
            \n\t* dd - descending date\
            \n\t* at - ascending temperature\
            \n\t* dt - descending temperature\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    return SUCSESS;
}

ProcResult open_file_cmd(char* arg){
    int year, month, day, hour, min, res, temp;
    file = fopen(arg, "r");
    if(file == NULL){
        printf("Failed to open %s file", arg);
        return FAIL;
    }
    printf("opened file: %s\n", arg);
    my_storage =  create_storage();
    uint32_t cntr = 0;
    while(1){
        res = fscanf(file, "%d;%d;%d;%d;%d;%d\n", &year, &month, &day, &hour, &min, &temp);
        //printf("new entry: %d.%d.%d %d:%d %d\n", year, month, day, hour, min, temp);

        if(res == EOF){
            break;
        }
        if(res == PARAMS_READED){
            push_to_storage(my_storage, (TempData){
            (uint16_t)year,
            (uint8_t)month,
            (uint8_t)day,
            (uint8_t)hour,
            (uint8_t)min,
            (int8_t)temp});
        }
        if(res < PARAMS_READED){
            char s[20];
            fscanf(file, "%[^\n]", s);     
            printf("ERROR at line %d: wrong format: %s\n",cntr, s);
        }
        cntr++;
    }
    return SUCSESS;
}

ProcResult get_statistic_by_year_cmd(char* arg){
    if(my_storage){
        //Запускаем поиск области, в которой будем искать данные
        long year = strtol(arg, NULL, 10);
        //проверить на границы диапазона
        if((year < 0) && (year >= UINT16_MAX)){
            printf("Failed execution of finding for date: wrong year\n");
            return FAIL;
        }
        DataRange y_range = find_in_year(my_storage, (Date){(uint16_t)year,0,0});
        if(y_range.num_of_records == 0){
            printf("Failed execution of finding for date: no information for this year\n");
            return FAIL;
        }

        //Выводим данные
        print_in_range(&y_range);

        //Вывод данных за диапазон
        int8_t min = min_temp(&y_range);
        int8_t max = max_temp(&y_range);
        float avg = avg_temp(&y_range);
        printf("Statistic for year %d:\n", year);
        printf("Minimal temeperature %d, maximal temperature %d, average temperature %0.3f\n", min, max, avg);
        return SUCSESS;
    }
    //если перед получением статистики нет данных о хранилище, то завершаем работу программы
    printf("No open file, execution terminated\n");
    return FAIL;
}

ProcResult get_statistic_by_month_cmd(char* arg){
    if(my_storage){
        //Запускаем поиск области, в которой будем искать данные
        long month = strtol(arg, NULL, 10);
        #warning FOR THIS IMPLEMENTATION THE YEAR IS TAKEN AUTOMATICALLY FROM THE STORAGE
        uint16_t year = get_the_year(my_storage);
        //проверить на границы диапазона
        if((month < 1) && (month > 12)){
            printf("Failed execution of finding for date: wrong month\n");
            return FAIL;
        }
        DataRange m_range = find_in_month(my_storage, (Date){year,(uint8_t)month, 0});
        if(m_range.num_of_records == 0){
            printf("Failed execution of finding for date: no information for this month\n");
            return FAIL;
        }

        //Выводим данные
        print_in_range(&m_range);

        //Вывод данных за диапазон
        int8_t min = min_temp(&m_range);
        int8_t max = max_temp(&m_range);
        float avg = avg_temp(&m_range);
        printf("Statistic for year %d and month %d:\n", year, month);
        printf("Minimal temeperature %d, maximal temperature %d, average temperature %0.3f\n", min, max, avg);
        return SUCSESS;
    }
    //если перед получением статистики нет данных о хранилище, то завершаем работу программы
    printf("No open file, execution terminated\n");
    return FAIL;
}

ProcResult add_new_entry_cmd(char* arg){
    if(my_storage){
        int year, month, day, min, hour, temp;
        uint8_t res;

        res = sscanf(arg, "%d.%d.%d;%d:%d;%d\n", &year, &month, &day, &hour, &min, &temp);
        
        if(res < PARAMS_READED){
            char s[20];
            res = sscanf(arg, "%[^\n]", s);     
            printf("ERROR %d=%s\n",res,s);
            return FAIL;
        }

        push_to_storage(my_storage, (TempData){
        (uint16_t)year,
        (uint8_t)month,
        (uint8_t)day,
        (uint8_t)hour,
        (uint8_t)min,
        (int8_t)temp});

        printf("inserted new data: %d.%d.%d; %d:%d; %d\n", 
                (uint16_t)year,
                (uint8_t)month,
                (uint8_t)day,
                (uint8_t)hour,
                (uint8_t)min,
                (int8_t)temp);
        return SUCSESS;
    }
    //если перед получением статистики нет данных о хранилище, то завершаем работу программы
    printf("No open file, execution terminated\n");
    return FAIL;
}

ProcResult delete_last_entry_cmd(char* arg){
    (void)arg;
    if(my_storage){
        pull_from_storage(my_storage);
        printf("Last entry erased\n");
        return SUCSESS;
    }
    //если перед получением статистики нет данных о хранилище, то завершаем работу программы
    printf("No open file, execution terminated\n");
    return FAIL;
}

ProcResult delete_entry_cmd(char* arg){
    if(my_storage){
        char* str_ptr = arg;

        //Обработка входной строки
        //Определяем год
        long y = strtol(str_ptr, NULL, 10);
        str_ptr = strchr(str_ptr, '.') + 1;

        //Определяем месяц
        long m = strtol(str_ptr, NULL, 10);
        str_ptr = strchr(str_ptr, '.') + 1;

        //Определяем день
        long d = strtol(str_ptr, NULL, 10);
        str_ptr = strchr(str_ptr, ';') + 1;

        //Определяем час
        long h = strtol(str_ptr, NULL, 10);
        str_ptr = strchr(str_ptr, ':') + 1;

        //Минуты
        long min = strtol(str_ptr, NULL, 10);
        str_ptr = strchr(str_ptr, ';') + 1;

        delete_entry(my_storage, 
            (Date){(uint16_t)y,(uint8_t)m,(uint8_t)d},
            (Time){(uint8_t)h,(uint8_t)min});

        printf("deleted data: %d.%d.%d; %d:%d\n", (uint16_t)y, (uint8_t)m, (uint8_t)d, (uint8_t)h, (uint8_t)min);
        return SUCSESS;
    }
    //если перед получением статистики нет данных о хранилище, то завершаем работу программы
    printf("No open file, execution terminated\n");
    return FAIL;

}
ProcResult show_all_data_cmd(char* arg){
    if(strcmp(arg, "ad") == 0){
        print_all_by_date(my_storage, ASCENDING);
        return SUCSESS;
    }
    if(strcmp(arg, "dd") == 0){
        print_all_by_date(my_storage, DESCENDING);
        return SUCSESS;
    }
    if(strcmp(arg, "at") == 0){
        print_all_by_temp(my_storage, ASCENDING);
        return SUCSESS;
    }
    if(strcmp(arg, "dt") == 0){
        print_all_by_temp(my_storage, DESCENDING);
        return SUCSESS;
    }
    printf("Wrong parameter entered, abort execution\n");
    return FAIL;
}

ProcResult unknown_command_cmd(char* arg){
    (void)arg;
    printf("UNKNOWN COMMAND, EXECUTION TERMINATED!!!\n");
    return FAIL;
}


ProcResult test_program(char* arg){
    (void)arg;

    printf("No parameters entered, called demonstration program:\n");

    //Создаём хранилище
    open_file_cmd("test.txt");

    //Загружаем данные   
    add_new_entry_cmd("2021.2.7;12:23;16");
    add_new_entry_cmd("2021.2.15;12:23;11");
    add_new_entry_cmd("2021.2.3;12:23;13}");
    add_new_entry_cmd("2021.2.30;12:23;24");

    //выводим статистику
    get_statistic_by_year_cmd("2011");
    get_statistic_by_month_cmd("6");

    //выводим записи
    show_all_data_cmd("ad");
    show_all_data_cmd("dd");
    show_all_data_cmd("at");
    show_all_data_cmd("dt");

    //удал+яем последние записи
    for(int i = 0; i < 5; i++){
        delete_last_entry_cmd(NULL);
    }
    show_all_data_cmd("ad");

    //удаляем конкретную запись
    delete_entry_cmd("2021.2.15;12:23");
    delete_entry_cmd("2021.2.3;12:23");
    delete_entry_cmd("2021.2.30;12:23");
    show_all_data_cmd("ad");

    return SUCSESS;
}



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
