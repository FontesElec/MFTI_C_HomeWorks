
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "temp_api.h"

void test_program(void);

// Массив обработчиков команд
struct CommandHandler handlers[] = {
    {"-h",  help_cmd},
    {"-f",  open_file_cmd},
    {"-y",  get_statistic_by_year_cmd},
    {"-m",  get_statistic_by_month_cmd},
    {"-n",  add_new_entry_cmd},
    {"-dl", delete_last_entry_cmd},
    {"-d",  delete_entry_cmd},
    {"-s",  show_all_data_cmd},
    {0, unknown_command_cmd} // Маркер конца массива
};


int main(int argc, char* argv[]) {

    //Если при запуске не передан ни один параметр, то запускаем просто демонстрационную программу
    if(argc == 1){
        test_program();
    }
    else{
        //Для остальных случаев проходим по аргументам командной строки и последовательно выполняем
        printf("argc: %d\n", argc);
        for(int i = 1; i < argc; i++){
            for(int j = 0; j < sizeof(handlers)/sizeof(handlers[0]); j++){
                //если ничего из списка нет, то дойдём до NULL, напишем сообщение и завершим работу программы
                if(handlers[j].command_name == NULL){
                    handlers[j].handler_func(NULL);
                    return 1;
                }
                if (strcmp(argv[i], handlers[j].command_name) == 0) {
                    //проверяем, является следующий аргумент параметром, или новой командой
                    if((i + 1 != argc) && (*argv[i+1] == '-')){
                        handlers[j].handler_func(NULL);
                    }
                    else{
                        handlers[j].handler_func(argv[i+1]);
                    i++;
                    }
                    break;             
                }            
            }
        } 
        
    }
    printf("Press any key to exit\n");
    getchar();  
    return 0;
}

void test_program(void){

    printf("No parameters entered, called demonstration program:\n");

    //Создаём хранилище
    open_file_cmd(NULL);

    //Загружаем данные   
    add_new_entry_cmd("2011.2.7;12:23;16");
    add_new_entry_cmd("2011.2.15;12:23;11");
    add_new_entry_cmd("2011.3.3;12:23;12");
    add_new_entry_cmd("2011.3.19;12:23;5");
    add_new_entry_cmd("2011.4.3;12:23;-3");
    add_new_entry_cmd("2011.4.19;12:23;-10");
    add_new_entry_cmd("2011.4.24;12:23;-28");
    add_new_entry_cmd("2011.5.3;12:23;-5");
    add_new_entry_cmd("2011.5.26;12:23;12");
    add_new_entry_cmd("2011.6.9;12:23;19");
    add_new_entry_cmd("2011.3.14;12:23;10");
    add_new_entry_cmd("2011.6.3;12,:23;16");
    add_new_entry_cmd("2011.4.13;12:23;-7");
    add_new_entry_cmd("2011.2.3;12:23;13}");
    add_new_entry_cmd("2011.5.19;12:23;0");
    add_new_entry_cmd("2011.4.30;12:23;-13");
    add_new_entry_cmd("2011.2.9;12:23;17");
    add_new_entry_cmd("2011.3.26;12:23;0");
    add_new_entry_cmd("2011.5.13;12:23;-1");
    add_new_entry_cmd("2011.2.30;12:23;24");

    //выводим статистику
    get_statistic_by_year_cmd("2011");
    get_statistic_by_month_cmd("6");

    //выводим записи
    show_all_data_cmd("ad");
    show_all_data_cmd("dd");
    show_all_data_cmd("at");
    show_all_data_cmd("dt");

    //удаляем последние записи
    for(int i = 0; i < 15; i++){
        delete_last_entry_cmd(NULL);
    }
    show_all_data_cmd("ad");

    //удаляем конкретную запись
    delete_entry_cmd("2011.2.15;12:23");
    show_all_data_cmd("ad");
}