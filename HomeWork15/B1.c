/*
        Описана структура данных для хранения информации об использованной памяти:
        typedef struct list {
            void *address;
            size_t size;
            char comment[64];
            struct list *next;
        } list;
        Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.
        Прототип функции:

        size_t totalMemoryUsage(list *head)
*/

#include <stdio.h>
#include <stdint.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

size_t totalMemoryUsage(list *head){
    size_t total_size = 0;
    while(head != 0){
        total_size += head->size;
        head = head->next;
    }
    return total_size;
}

uint64_t findMaxBlock(list *head){
    size_t max_size = 0;
    list* max_size_list = NULL;
    while(head != 0){
        if(head->size > max_size){
            max_size_list = head;
            max_size = head->size;
        }
        head = head->next;
    }
    if(max_size_list == NULL){
        return 0;
    }
    return max_size_list->address;
}

int main(void){
    int iter = 0;
    list* my_list = NULL;
    list* prev_list = NULL;

    scanf("%d", &iter);
    
    for(int i = 0; i < iter; i++){
        if(i==0){
            my_list = (list*)malloc(sizeof(list));
            scanf("%u ", "%d", my_list->address, my_list->size);
            my_list->next = NULL;
            prev_list = my_list;
        }
        else{
            prev_list->next = (list*)malloc(sizeof(list));
            scanf("%u ", "%d", prev_list->next->address, prev_list->next->size);
            prev_list->next = NULL;
            prev_list = prev_list->next;
        }
    }

    printf("%u", findMaxBlock(my_list));
    printf("%u", totalMemoryUsage(my_list));
    return 0;
}