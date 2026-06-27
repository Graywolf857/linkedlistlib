#ifndef linked_list_h
#define linked_list_h

typedef struct{
    int data;
    struct Node *next;
} Node;

typedef struct{
    Node *head;
    int size;
} LinkedList;

void list_init(LinkedList *list);

#endif
