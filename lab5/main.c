# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "intlist.h"


int main()
{
    IntList *p_list;
    int data_arr[] = {1, 2, 3, 4, 5};
    create_list_from_data(&p_list, data_arr, 5);
    for(int i = 0; i < p_list->size; i++)
    {
        printf("%d\n", p_list->data[i]);
    }
    printf("==========\n");
    list_append(p_list, 6);
    for(int i = 0; i < p_list->size; i++)
    {
        printf("%d\n", p_list->data[i]);
    }
    printf("==========\n");
    list_insert(p_list, 7, 2);
    for(int i = 0; i < p_list->size; i++)
    {
        printf("%d\n", p_list->data[i]);
    }
    printf("==========\n");
    list_delete(p_list, 3);
    for(int i = 0; i < p_list->size; i++)
    {
        printf("%d\n", p_list->data[i]);
    }
    printf("==========\n");
    list_destroy(p_list);
    list_get(p_list, 2);
}