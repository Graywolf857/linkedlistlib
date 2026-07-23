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

int list_insert_after(LinkedList *list, int target, int value){
    /* Find the first node containing target
     * Insert a new node immediately after in
     * return 1 if it succeeds
     * return 0 if target is not found
     * return 0 if malloc fails 
     */

    if(list->size == 0){
        printf("The list is empty\n");
        return 0;
    }

    Node *current = list->head;

    while(current != NULL && current->data != target){
        current = current->next;
    }

    if(current == NULL){
        printf("target was not found in the list\n");
        return 0;
    }

    Node *node = malloc(sizeof(Node));

    if(node == NULL){
        return 0;
    }

    node->data = value;

    Node *after_insert_node = current->next;

    current->next = node;
    node->next = after_insert_node;

    list->size++;
    return 1;
}

int list_pop_front(LinkedList *list){
    /*
    - Remove the first node.
    - Free its memory.
    - Update head.
    - Decrement size.
    - 1 if node was removed
    - 0 if the list is empty
    */

    if(list->size == 0){
        printf("The list is empty\n");
        return 0;
    }
    
    Node *old_node = list->head;

    list->head = old_node->next;

    free(old_node);

    old_node = NULL;
    list->size--;
    return 1;
}

int list_remove(LinkedList *list, int value){

    /* remove the first occurrence of value
     * free the removed node
     * update links correctly
     * decrement size
     */

    if(list->head == NULL){
        printf("list is empty");
        return 0;
    }

    Node *traverse = list->head;

    Node *node_before = traverse;

    while(traverse != NULL && traverse->data != value){
        node_before = traverse;
        traverse = traverse->next;
    }

    if (traverse == NULL){
        printf("The value was not found");
        return 0;
    }

    if(node_before == traverse){
        list->head = traverse->next;
    }else {
        node_before->next = traverse->next;
    }

    free(traverse);

    list->size--;
    return 1;
}

Node *list_find(LinkedList *list, int value){

    Node *node = list->head;

    while(node != NULL && node->data != value){
        node = node->next;
    }

    if (node == NULL){
        return NULL;
    }

    return node;
}

int list_size(const LinkedList *list){
    return list->size;
}

void list_clear(LinkedList *list){

    Node *node = list->head;
    Node *node_freed = node;

    while (node != NULL){

        node_freed = node;
        
        node = node->next;

        free(node_freed);

    }

    list->head = NULL;
    list->size = 0;
}
