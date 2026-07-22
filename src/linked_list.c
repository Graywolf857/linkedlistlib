#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

void list_init(LinkedList *list){
    /*Initialize empty list
     * head should be NULL
     * size should be 0
     */
    list->size = 0;
    list->head = NULL;
}

int list_push_front(LinkedList *list, int value){
    /*Allocate a new node
     * Insert at beginning
     * update head
     * increment size
     * return 0 if malloc fails
     */
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL){
        return 0;
    }

    node->data = value;
    node->next = list->head;
    list->head = node;
    list->size++;

    return 1;
}
int list_push_back(LinkedList *list, int value){
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL){
        return 0;
    }

    if (list->size == 0){
        node->data = value;
        node->next = list->head;
        list->head = node;
        list->size++;
    }



    list->size++;
    return 1;
}
