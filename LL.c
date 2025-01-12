# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Node{
    int data;
    Node *next;
} Node;

typedef struct LL{
    Node *head;
    int size;
}LL;

void create_node(Node *n, int data){
    n = (Node *)malloc(sizeof(Node));
    n->data = data;
}

void create_LL(LL *list, Node *head, int size){
    list = (LL *)malloc(sizeof(LL));
    list->head = head;
    list->size = size;
}

void insert_node(LL *list, Node *new, int index){
    Node *cur = list->head;
    for(int i = 0; i < index-1; i++){
        cur = cur->next;
    }
    Node *post = cur->next;
    cur->next = new;
    new->next = post;
    list->size++;
}

void delete_node(LL *list, int index){
    Node *cur = list->head;
    for(int i = 0; i < index-1; i++){
        cur = cur->next;
    }
    Node *skip = cur->next;
    Node *post_skip = skip->next;
    cur->next = post_skip;
    free(skip);
    list->size--;
}

int find_node(LL *list, int target){
    Node *cur = list->head;
    int index = 0;
    while(cur->next != NULL){
        if(cur->data == target){
            return index;
        }
        index++;
        cur = cur->next;
    }
    return -1;
}

void loop(LL *list){
    int *node_data = (int *)malloc(list->size * sizeof(int));
    int count = 0;
    Node *cur = list->head;
    while(cur->next != NULL){
        for(int i = 0; i < count; i++){
            if(cur->data == node_data[i]){
                return 1;
            }
        }
        node_data[count] = cur->data;
        count++;
        cur = cur->next;
    }
    return 0;
}

void delete_LL(LL *list){
    free(list);
}