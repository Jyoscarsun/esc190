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
    q->arr = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        q->arr[i] = 0;
    }
    q->size = size;
    q->start = size / 2;
    q->end = size / 2 + 1;
}

void enqueue(CircularQueue *q, int item){
    if(q->arr[q->start] == 0){
        q->arr[q->start] = item;
    }
    else{
        q->arr[q->end] = item;
        if(q->end+1 == q->size){
            q->end = 0;
        }
        else{
            q->end++;
        }
    }
}

int dequeue(CircularQueue *q){
    int res = q->arr[q->start];
    q->arr[q->start] = 0;

    if(q->start+1 == q->size){
        q->start = 0;
    }
    else{
        q->start++;
    }
    return res;
}

void printQueue(CircularQueue *q){
    int q_size = 0;
    if(q->end >= q->start){
        q_size = q->end - q->start;
    }
    else{
        q_size = q->size - q->start + q->end;
    }
    int ind = q->start;
    for(int i = 0; i < q_size-1; i++){
        printf("%d->", q->arr[ind]);
        if(ind+1 == q->size){
            ind = 0;
        }
        else{
            ind++;
        }
    }
    printf("%d\n", q->arr[ind]);
}

int queuecmp(CircularQueue *q1, CircularQueue *q2){
    int q1_ind = q1->start;
    int q2_ind = q2->start;

    while(q1_ind != q1->end+1 || q2_ind != q2->end+1){
        if(q1->arr[q1_ind] < q2->arr[q2_ind]){
            return -1;
        }
        else if(q1->arr[q1_ind] > q2->arr[q2_ind]){
            return 1;
        }
        else{
            q1_ind++;
            q2_ind++;
            if(q1_ind >= q1->size){
                q1_ind = 0;
            }
            if(q2_ind >= q2->size){
                q2_ind = 0;
            }
        }
    }
    return 0;
}

void expand(CircularQueue *q){
    CircularQueue *new_q = (CircularQueue *)malloc(sizeof(CircularQueue));
    new_q->arr = (int *)malloc(q->size * 2 * sizeof(int));
    int q_size = 0;
    if(q->end >= q->start){
        q_size = q->end - q->start;
    }
    else{
        q_size = q->size - q->start + q->end;
    }

    int ind = q->start;
    for(int i = 0; i < q_size; i++){
        new_q->arr[i] = q->arr[ind];
        ind++;
        if(ind == q->size){
            ind = 0;
        }
    }
    new_q->size = q->size * 2;
    new_q->start = q->start;
    if(new_q->start + q_size >= new_q->size){
        new_q->end = q_size - (new_q->size - new_q->start);
    }
    else{
        new_q->end = new_q->start + q_size;
    }
    q = new_q;
}

int main(){
    CircularQueue q1, q2;
    init(&q1, 10);
    init(&q2, 10);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);


    enqueue(&q2, 6);
    enqueue(&q2, 7);
    enqueue(&q2, 8);
    enqueue(&q2, 9);
    enqueue(&q2, 10);

    printQueue(&q1);
    printQueue(&q2);

    printf("%d\n", queuecmp(&q1, &q2));

    return 0;
}