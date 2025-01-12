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

int queue_len(CircularQueue *q){
    int res = 0;
    for(int i = 0; i < q->size; i++){
        if(q->arr[i] != 0){
            res++;
        }
    }
    return res;
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

int is_empty(CircularQueue q){
    return q->start == q->end;
}

typedef struct Graph{
    int num_nodes;
    int *adj_matrix;
}Graph;

void construct_graph(Graph **P_g, int num_nodes){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->num_nodes = num_nodes;
    g->adj_matrix = (int *)malloc(num_nodes * num_nodes * sizeof(int));
    for(int i = 0; i < num_nodes; i++){
        for(int j = 0; j < num_nodes; j++){
            g->adj_matrix[i * num_nodes + j] = 0;
        }
    }
    *P_g = g;
}

void destruct_graph(Graph *g){
    free(g->adj_matrix);
    free(g);
}


int get_edge(Graph *g, int i, int j){
    return g->adj_matrix[i * g->num_nodes + j];
}

void set_edge(Graph *g, int i, int j, int val){
    g->adj_matrix[i * g->num_nodes + j] = val;
    g->adj_matrix[j * g->num_nodes + i] = val;
}

void BFS(Graph *g, int start_node){
    int *visited_mask = (int *)malloc(g->num_nodes * sizeof(int));
    for(int i = 0; i < g->num_nodes; i++){
        visited_mask[i] = 0;
    }

    CircularQueue q;
    init(&q, g->num_nodes);
    enqueue(&q, start_node);
    visited_mask[start_node] = 1;
    while(!is_empty(q)){
        int node = dequeue(&q);
        printf("%d\n", node);
        for(int i = 0; i < g->num_nodes; i++){
            if(get_edge(g, node, i) == 1 && visited_mask[i] == 0){
                enqueue(&q, i);
                visited_mask[i] = 1;
            }
        }
    }
}

void DFS(Graph *g, int start_node){
    int *visited_mask = (int *)malloc(g->num_nodes * sizeof(int));
    for(int i = 0; i < g->num_nodes; i++){
        visited_mask[i] = 0;
    }

    int *stack = (int *)malloc(g->num_nodes * sizeof(int));
    int end = 0;
    stack[end++] = start_node;
    visited_mask[start_node] = 1;
    while(end > 0){
        int node = stack[--end];
        printf("%d\n", node);
        for(int i = 0; i < g->num_nodes; i++){
            int has_edge = get_edge(g, node, i);
            int is_visited = visited_mask[i];
            if(has_edge && !is_visited){
                stack[end++] = i;
                visited_mask = 1;
            }
        }
    }
}

int main()
{
    Graph *g;
    construct_graph(&g, 5);
    set_edge(g, 0, 1, 1);
    set_edge(g, 1, 2, 1);
    set_edge(g, 1, 3, 1);
    set_edge(g, 0, 4, 1);

    printf("\n\n ***BFS ***\n");
    BFS(g, 0);
    
    return 0;
}