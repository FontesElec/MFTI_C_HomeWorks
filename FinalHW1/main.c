
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "temp_api.h"

// Массив обработчиков команд
struct CommandHandler handlers[] = {
    {"-h",  help_cmd},
    {"-f",  open_file_cmd},
    {"-y",  get_statistic_by_year_cmd},
    {"-m",  get_statistic_by_month_cmd},
    {"-n",  add_new_entry_cmd},
    {"-l",  delete_last_entry_cmd},
    {"-d",  delete_entry_cmd},
    {"-s",  show_all_data_cmd},
    {"-t",  test_program},
    {0, unknown_command_cmd} // Маркер конца массива
};


int main(int argc, char* argv[]) {

    //Если при запуске не передан ни один параметр, то запускаем просто демонстрационную программу
    if(argc == 1){
        help_cmd(NULL);
    }
    else{
        //Для остальных случаев проходим по аргументам командной строки и последовательно выполняем
        printf("argc: %d\n", argc);
        for(int i = 1; i < argc; i++){
            for(size_t j = 0; j < sizeof(handlers)/sizeof(handlers[0]); j++){
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

