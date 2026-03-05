/*
В программе описана структура для хранения двоичного дерева:
typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;
Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу:

void btUpView(tree *root)
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct list {
    char word[20];
    struct list *next;
};

void print_list(struct list* my_list){
    my_list = my_list->next;
    while(my_list){
        printf("%s ", my_list->word);
        my_list = my_list->next;
    }
}

void delete_list(struct list* my_list){
    struct list* del_list = NULL;
    while(my_list){
        del_list = my_list;
        my_list = my_list->next;
        free(del_list);
    }
}

void swap_elements(struct list* prev_node, struct list* next_node){
    //забираем указатель на того, которого следует менять
    struct list* tmp = prev_node->next;
    //Задаём новый следующий узел
    prev_node->next = next_node-> next;
    //Восстанавливаем ссылку на вставляемый элемент
    next_node->next = tmp;
    //Восстанавливаем правильную последовательность последующих узлов
    tmp = prev_node->next->next;
    prev_node->next->next = next_node->next->next;
    next_node->next->next = tmp;
}


void add_to_list(struct list* my_list, struct list* new_node){
    //Отыскиваем место для вставки
    while((my_list->next) && (strcmp(my_list->next->word, new_node->word) < 0)){
        my_list = my_list->next;
    }
    new_node->next = my_list->next;
    my_list->next = new_node;
}






int main(void){
    
    struct list* head = calloc(1, sizeof(struct list));
    struct list* tmp_list = calloc(1, sizeof(struct list));
    char ch = 0;
    char* c_ptr = tmp_list->word;
    while((ch = getchar()) != '.' && ch != EOF){
        if(ch != ' '){
            *c_ptr = ch;
            c_ptr++;
        }
        else{
            add_to_list(head, tmp_list);
            tmp_list = calloc(1, sizeof(struct list));
            c_ptr = tmp_list->word;
        }            
    }
    add_to_list(head, tmp_list);
    print_list(head);
    delete_list(head);
}
