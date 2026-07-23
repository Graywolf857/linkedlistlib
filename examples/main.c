#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int main(){
    LinkedList spell_list;

    list_init(&spell_list);
    list_insert_after(&spell_list, 0, 4);

    list_print(&spell_list);

    list_push_back(&spell_list, 12);

    list_print(&spell_list);

    list_push_front(&spell_list, 15);

    list_print(&spell_list);

    list_push_front(&spell_list, 17);

    list_print(&spell_list);

    list_push_back(&spell_list, 1);

    list_print(&spell_list);

    list_push_front(&spell_list, 2000);

    list_insert_after(&spell_list, 17, 4);
    list_insert_after(&spell_list, 0, 4);

    list_print(&spell_list);

    list_pop_front(&spell_list);
    list_print(&spell_list);

    return 0;
}
