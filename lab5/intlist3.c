# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "intlist.h"

// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(IntList **p_IntList, int *data_arr, int size){
    *p_IntList = (IntList *)malloc(sizeof(IntList));
    (*p_IntList)->data = (int *)malloc(size * sizeof(int));
    memmove((*p_IntList)->data, data_arr, sizeof(int));
    (*p_IntList)->size = size;
    (*p_IntList)->capacity = size;
}

void list_append(IntList *list, int new_elem){
    // if(list->size + 1 == list->capacity){
    //     list->data = (int *)realloc(list->data, list->size * 2 * sizeof(int));
    //     list->capacity = list->size * 2;
    // }
    if(list->size + 1 == list->capacity){
        list->data = (int *)realloc(list->data, (list->capacity+1)*sizeof(int));
        list->capacity++;
    }
    list->data[list->size] = new_elem;
    list->size++;
}

void list_insert(IntList *list, int new_elem, int index)
{
    // if(list->size + 1 == list->capacity){
    //     list->data = (int *)realloc(list->data, list->size * 2 * sizeof(int));
    //     list->capacity = 2 * list->size;
    // }
    if(list->size + 1 == list->capacity){
        list->data = (int *)realloc(list->data, (list->capacity+1) * sizeof(int));
        list->capacity++;
    }
    memmove(list->data+index+1, list->data+index, (list->size-index+1)*sizeof(int));
    list->data[index] = new_elem;
    list->size++;
}

void list_delete(IntList *list, int index){
    memmove(list->data+index, list->data+index+1, (list->size-index)*sizeof(int));
    list->size--;
    if(list->size < list->capacity / 2){
        list->data = (int *)realloc(list->data, (list->capacity/2)*sizeof(int));
        list->capacity /= 2;
    }
}

void list_destroy(IntList *list){
    free(list->data);
    free(list);
}

int list_get(IntList *list, int index){
    return list->data[index];
}