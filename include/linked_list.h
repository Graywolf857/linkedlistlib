#ifndef linked_list
#define linked_list

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct{
    Node *head;
    int size;
} LinkedList;

void list_init(LinkedList *list);

int list_push_front(LinkedList *list, int value);

int list_push_back(LinkedList *list, int value);

void list_print(const LinkedList *list);

int list_insert_after(LinkedList *list, int target, int value);

int list_pop_front(LinkedList *list);

int list_remove(LinkedList *list, int value);

#endif
