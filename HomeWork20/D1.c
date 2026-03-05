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
typedef int datatype;

/*
10
├─L: 5
│   ├─L: 3
│   │   └─L: 1
│   │       └─L: 0
│   └─R: 7
│       └─L: 6
└─R: 15
    ├─L: 13
    │   └─R: 14
    └─R: 18
*/

typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;

//Если я правильно понял идею задания, то идея в том, тобы описать максимально левое, а затем максимально правое крыло
void btUpView(tree *root){

    if(!root){
        return;
    }
    
    //Раз задание настолько ограничивает в возможностях, то будут некоторые "хитрости"
    tree* array[1000] = {NULL}; //Вместо написания обратного односвязгого списка

    tree* cur_r = root;
    int cntr = 0;
    //Запомнили весь путь левой ветки
    while(cur_r){
        array[cntr] = cur_r;
        cntr++;
        cur_r = cur_r -> left;
    }

    //А теперь печатаем в обратную сторону
    for(int i = cntr - 1; i >= 0; i--){
        printf("%d ", array[i]->key);
    }

    //теперь идём по правой ветке
    cur_r = root->right;
    while(cur_r){
        printf("%d ", cur_r->key);
        cur_r = cur_r -> right;
    }
    
}