/*
ВВ программе описано двоичное дерево:
typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent; //ссылка на родителя
} tree;
Требуется реализовать функцию, которая по ключу возвращает адрес соседнего элемента - брата. Если такого ключа нет или у узла нет брата, то необходимо вернуть 0.
Прототип функции:

tree * findBrother(tree *root, int key)
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int datatype;

typedef struct tree {
    datatype key;
    struct tree *left, *right;
    struct tree *parent; //ссылка на родителя
} tree;

tree * findBrother(tree *root, int key){
    tree *tmp = root;
    tree * prev = NULL;
    if(tmp->key == key){
        return NULL;
    }
    //Ищем нужный ключ
    while(tmp && (tmp->key != key)){
        prev = tmp;
        if(key > tmp->key){
            tmp = tmp->right;
        }
        else{
            tmp = tmp -> left;
        }
    }
    //Если ключ нашли, то по родителю (предыдущий элемент) смотрим на наличие "брата"
    if(tmp){
        if(prev->left == tmp){
            return prev->right;
        }
        else{
            return prev->left;
        }
    }
    return tmp;
}