# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "intlist.h"

void create_list_from_data(IntList **p_IntList, int *data_arr, int size)
{
    *p_IntList = (IntList *)malloc(sizeof(IntList));
    (*p_IntList)->data = (int *)malloc(size*sizeof(int)); // Allocate memory for the data
    memmove((*p_IntList)->data, data_arr, size*sizeof(int)); // Initialize the data
    (*p_IntList)->size = size; // Initialize the size
    (*p_IntList)->capacity = size; // Initialize the capacity
}

void list_append(IntList *list, int new_elem)
{
    // Realloc list-> to have double the capacity as before
    list->data = (int *)realloc(list->data, (list->size + 1) * sizeof(int));
    list->data[list->size] = new_elem; // Add in the new element
    list->capacity = list->size+1; // Update the capacity (which is double of size prior)
    list->size++; // Update the size
    shrink_capacity(list);
}

void list_insert(IntList *list, int new_elem, int index)
{
    // check whether the list can take an insertion of a new element
    if(list->capacity == list->size)
    {
        list->data = (int *)realloc(list->data, (list->size + 1) * sizeof(int));
        list->capacity = list->size+1;
        list->size++;
    }
    // Move the first index elements to index + 1 location
    memmove(list->data+index+1, list->data+index, (list->size-index+1)*sizeof(int));
    // Now set the element at index location to the new element
    list->data[index] = new_elem;
    shrink_capacity(list);
}

void list_delete(IntList *list, int index)
{
    // Move the elements after index+1 up one place to index
    memmove(list->data+index, list->data+index+1, (list->size-index)*sizeof(int));
    // The size of int decreases by 1
    list->size--;
    shrink_capacity(list);
}

void list_destroy(IntList *list)
{
    free(list->data);
    free(list);
}

void shrink_capacity(IntList *list)
{
    if(list->size < list->capacity / 2)
    {
        list->data = (int *)realloc(list->data, list->size / 2 * sizeof(int));
    }
}

int list_get(IntList *list, int index)
{
    return list->data[index];
}
