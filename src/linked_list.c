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
    struct Node *node = malloc(sizeof(Node));

    if (node == NULL){
        return 0;
    }

    node->data = value;
    node->next = list->head;
    list->head = node;
    list->size++;

    return 1;
}

void list_print(const LinkedList *list){
    
    Node *current = list->head;

    if (list->size == 0){
        printf("List is empty\n");
    }else {
        while(current != NULL){
            printf("[%d] -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
    
}


int list_push_back(LinkedList *list, int value){
    struct Node *node = malloc(sizeof(Node));
    if (node == NULL){
        return 0;
    }

    Node *current = NULL;
    current = list->head;

    if (list->size == 0){
        node->data = value;
        node->next = list->head;
        list->head = node;
    }else {
        node->data = value;
        node->next = NULL;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = node;
    }

    list->size++;
    return 1;
}

