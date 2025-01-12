# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct CircularQueue{
    int *arr;
    int size;
    int start;
    int end;
} CircularQueue;

void init(CircularQueue *q, int size){
    q = (CircularQueue *)malloc(sizeof(CircularQueue));
    q->arr = (int *)calloc(q->arr, sizeof(int)*size);
    q->size = size;
    q->start = size/2;
    q->end = size/2;
}

void enqueue(CircularQueue *q, int item){
    if(q->arr[q->start] == 0){
        q->arr[q->start] = item;
    }
    else{
        if(q->end+1 == q->size){
            q->arr[0] = item;
            q->end = 0;
        }
        else{
            q->arr[q->end+1] = item;
            q->end += 1;
        }
    }
}

int dequeue(CircularQueue *q){
    int res = q->arr[q->start];
    q->arr[q->start] = 0;
    
    if(q->start == q->size-1){
        q->start = 0;
    }
    else{
        q->start += 1;
    }

    return res;
}

int queuecmp(CircularQueue *q1, CircularQueue *q2){
    int cmpsize = min(q1->size, q2->size);

    for(int i = 0; i < cmpsize; i++){
        int q1_ind = q1->start + i;
        int q2_ind = q2->start + i;
        if(q1_ind >= q1->size){
            q1_ind = q1->start + i - q1->size;
        }
        if(q2_ind >= q2->size){
            q2_ind = q2->start + i - q2->size;
        }
        if(q1->arr[q1_ind] > q2->arr[q2_ind]){
            return 1;
        }
        else if(q1->arr[q1_ind] < q2->arr[q2_ind]){
            return -1;
        }
    }
    return 0;
}

void queue_sort(CircularQueue **q_list, int size){
    CircularQueue *qmin = (CircularQueue *)malloc(sizeof(CircularQueue));
    qmin = q_list[0];
    int ind = 0;
    for(int i = 0; i < size; i++){
        if(queuecmp(qmin, q_list[i]) == 1){
            qmin = q_list[i];
            ind = i;
        }
        q_list[i], q_list[ind] = q_list[ind], q_list[i];
    }
}

void expand(CircularQueue *q){
    q->arr = (int *)realloc(q->arr, q->size*2);
    q->size *= 2;

    if(q->end < q->start){
        for(int i = 0; i < q->end+1; i++){
            q->arr[q->size/2+i] = q->arr[i];
            q->arr[i] = 0;
        }
        q->end = q->size/2+q->end-1;
    }
}