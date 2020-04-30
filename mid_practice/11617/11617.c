#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *prev;
    struct node *next;
}Node;

typedef struct terminal{
    Node *head;
    Node *tail;
}Terminal;

Terminal *initTerminal(){
    Terminal *t = (Terminal *)malloc(sizeof(Terminal));
    t->head = NULL;
    t->tail = NULL;

    return t;
}

Node **initMap(int len){
    Node **nodeMap = (Node **)malloc(sizeof(Node *) * len);
    for(int i = 0; i < len; i++){
        nodeMap[i] = NULL;
    }

    return nodeMap;
}

// Add New Node into List at the Head
Node *push(Terminal *terminal, Node *node){
    if(terminal->head == NULL && terminal->tail == NULL){
        // Adapt New Head
        node->prev = NULL;
        node->next = NULL;

        // Adapt Terminal Tail
        terminal->tail = node;

        // Adapt Terminal Head
        terminal->head = node;
    }else{
        // Adapt New Head
        node->prev = NULL;
        node->next = terminal->head;

        // Adapt Old Terminal Head
        terminal->head->prev = node;

        // Adapt Terminal Head
        terminal->head = node;
    }

    return node;
}

// Add New Value into List at the Tail
Node *add(Terminal *terminal, Node **map, int value){
    // Adapt New Tail
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = terminal->tail;
    newNode->next = NULL;

    // Adapt Map
    map[value] = newNode;

    if(terminal->head == NULL){
        // Adapt Terminal Head
        terminal->head = newNode;

        // Adapt Terminal Tail
        terminal->tail = newNode;
    }else{
        // Adapt Old Terminal Tail
        terminal->tail->next = newNode;

        // Adapt Terminal Tail
        terminal->tail = newNode;
    }

    return newNode;
}

// Remove The Node From List
Node *erase(Terminal *terminal, Node **map, int value){
    if(map[value] == terminal->head){
        terminal->head = map[value]->next;

        map[value]->prev = NULL;
        map[value]->next = NULL;
    }else if(map[value] == terminal->tail){
        terminal->tail = map[value]->prev;

        map[value]->prev = NULL;
        map[value]->next = NULL;
    }else{
        // Adapt The Next Node of Erasing Node 
        map[value]->prev->next = map[value]->next;
        // Adapt The Previous Node of Erasing Node 
        map[value]->next->prev = map[value]->prev;

        // Adapt The Erasing Node
        map[value]->prev = NULL;
        map[value]->next = NULL;
    }

    return map[value];
}

void showList(Terminal *terminal, int nodeNumber){
    Node *temp = terminal->head;
    for(int i = 0; i < nodeNumber; i++){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void showListFormal(Terminal *terminal, int nodeNumber){
    Node *temp = terminal->head;
    for(int i = 0; i < nodeNumber; i++){
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main(){
    int n = 0, m = 0;
    scanf("%d %d\n", &n, &m);

    Terminal *terminal = initTerminal();
    Node **nodeMap = initMap(n);

    for(int i = 1; i <= n; i++){
        add(terminal, nodeMap, i);
    }

    // showList(terminal, n);

    for(int i = 0; i < m; i++){
        int em = 0;
        scanf("%d\n", &em);

        Node* erasedNode = erase(terminal, nodeMap, em);
        // showList(terminal, n-1);
        push(terminal, erasedNode);
        // showList(terminal, n);
    }

    showListFormal(terminal, n);

    return 0;
}