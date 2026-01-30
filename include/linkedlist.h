#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node Node;  

struct Node {              
    int data;
    Node *next;
};

typedef struct LinkedList {
    Node *head;          
    Node *tail;
    int created;
} LinkedList;

LinkedList createList(int data);
Node *createNode(int data);

Node *insertAtTail(LinkedList *list, int data);
Node *insertAtHead(LinkedList *list, int data);
Node *insertAtNode(LinkedList *list, Node *node, int data);

int sizeOfLinkedList(LinkedList *list);
int isEmpty(LinkedList *list);

struct Node *shiftList(LinkedList *list);
void popList(LinkedList *list);
void popNode(LinkedList *list, Node *node);

void freeLinkedList(LinkedList *list);
void printLinkedList(LinkedList *list);
#endif
