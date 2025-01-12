#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node{
    char *value;
    struct LinkedList *neighbours;
}Node;

typedef struct LinkedListNode{
    char *value;
    struct LinkedListNode *next;
}LinkedListNode;

typedef struct LinkedList{
    LinkedListNode *head;
}LinkedList;

void create_node(Node *node, char *value){
    node->value = (char *)malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->neighbours = malloc(sizeof(LinkedList));
    node->neighbours->head = malloc(sizeof(LinkedListNode));
}

void create_LinkedListNode(LinkedListNode *node, char *value){
    node->value = (char *)malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->next = NULL;
}

void create_LinkedList(LinkedList *list){
    list->head = (LinkedListNode *)malloc(sizeof(LinkedListNode));
}

void add(LinkedList *list, char *value){
    LinkedListNode *new_node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    create_LinkedListNode(new_node, value);
    if (list->head->next == NULL){
        create_LinkedListNode(list->head, value);
    }
    else{
        LinkedListNode *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        create_LinkedListNode(current->next, value);
    }
}

int are_nodes_linked(Node node1, Node node2)
{
    LinkedListNode *current = node1.neighbours->head;
    while(current != NULL){
        if(strcmp(current->value, node2.value) == 0){
            // If present in the neighbour list, return 1
            return 1;
        }
        current = current->next;
    }
    return 0; // If not present in neighbour list, return 0
}

Node *get_node_by_str(Node **nodes, char *node_str)
{
    for(int i = 0; i < sizeof(nodes)/sizeof(nodes[0]); i++){
       if(strcmp(nodes[i]->value, node_str) == 0)
       {
            return nodes[i];
       }
    }
    return NULL;
}

int are_airports_linked(Node **airports, char *airport1, char *airport2){
// Return 1, the airports are linked
// Return -1, the airports are not linked
{
    Node *airport1_node = get_node_by_str(airports, airport1);
    Node *airport2_node = get_node_by_str(airports, airport2);
    if(airport1_node == NULL || airport2_node == NULL){
        return 0;
    }
    return are_nodes_linked(*airport1_node, *airport2_node);
}
}

Node **make_airport_graph(){
    Node *yyz = malloc(sizeof(Node));
    Node *yvr = malloc(sizeof(Node));
    Node *yul = malloc(sizeof(Node));
    Node *whitehorse = malloc(sizeof(Node));
    create_node(yyz, "YYZ");
    create_node(yvr, "YVR");
    create_node(yul, "YUL");
    create_node(whitehorse, "Whitehorse");

    add(yyz->neighbours, "YYZ");
    add(yyz->neighbours, "YUL");
    add(yvr->neighbours, "YYZ");
    add(yvr->neighbours, "YUL");
    add(yvr->neighbours, "Whitehorse");
    add(yul->neighbours, "YYZ");
    add(yul->neighbours, "YVR");
    add(whitehorse->neighbours, "YVR");

    Node **airports = malloc(4 * sizeof(Node *));
    airports[0] = yyz;
    airports[1] = yvr; 
    airports[2] = yul;
    airports[3] = whitehorse;
    return airports;
}

int main(){
    Node **airports = make_airport_graph();
    if(are_airports_linked(airports, "YYZ", "YUL") == 1){
        printf("Toronto (YYZ) is connected to Montreal (YUL)\n");
    }
    else{
        printf("Toronto (YYZ) is not connected to Montreal (YUL)\n");
    }   
}

