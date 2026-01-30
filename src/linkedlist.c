#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList createList(int data)
{
    LinkedList list;
    list.head = (Node *)malloc(sizeof(Node));
    list.head->data = data;
    list.tail = list.head;
    return list;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    return newNode;
}

Node *insertAtHead(LinkedList *list, int data)
{
    Node *newNode = createNode(data);

    // swap the tail with new node

    // make new node point to head
    newNode->next = list->head;
    // replace head with new node
    list->head = newNode;
    return newNode;
}

Node *insertAtTail(LinkedList *list, int data)
{
    Node *newNode = createNode(data);

    // swap the tail with new node

    // make old tail point to new tail
    list->tail->next = newNode;
    // replace old tail with new tail
    list->tail = newNode;

    return newNode;
}

Node *insertAtNode(LinkedList *list, Node *node, int data)
{
    Node *newNode = createNode(data);

    if (node == list->head)
    {
        newNode->next = list->head;

        // replace head with new node
        list->head = newNode;

        return newNode;
    }

    if (node == list->tail)
    {
        // make old tail point to new tail
        list->tail->next = newNode;
        // replace old tail with new tail
        list->tail = newNode;

        return newNode;
    }

    // if the node isnt the head
    Node *temp = list->head;
    Node *prev;
    int hasNode = 0;

    // loop through list until it is the node
    while (temp != node || temp != NULL)
    {
        if (temp == node) {
            hasNode = 1;
        }

        // set previous to temp so when loop breaks it is the previous node
        prev = temp;

        temp = temp->next;
    }

    if (!hasNode) {
        fprintf(stderr, "Node not found in list.\n");
        free(newNode);
        return NULL;
    }

    // make sure the chain doesnt break
    // previous should point to new node
    prev->next = newNode;

    // the new node should point to the node being inserted at
    newNode->next = node;

    return newNode;
}

void popNode(LinkedList *list, Node *node)
{
    if (list->head->next == NULL)
    {
        fprintf(stderr, "Cant pop head if there are no other elements.\n");
        return;
    }

    // if its the head set head to element after head
    if (node == list->head)
    {
        list->head = list->head->next;
        free(node);
        return;
    }

    // if the node isnt the head
    Node *temp = list->head;
    Node *prev;
    int hasNode = 0;

    // loop through list until it is the node
    while (temp != node || temp != NULL)
    {
        // set new point to previous
        prev = temp;
        temp = temp->next;

        if (node == temp && temp != NULL) {
            hasNode = 1;
        }
    }

    if (!hasNode) {
        fprintf(stderr, "Node not found in list.\n");
        return;
    }

    // if its the tail set tail to previous element and remove current tail
    if (node == list->tail) {    
        free(node);
        list->tail = prev;
        // tail always points to null address
        list->tail->next = NULL;
        return;
    }


    // if its not tail or head
    // point previous node to removed node's next node so chain doesnt break
    prev->next = node->next;
    free(node);
}

Node *shiftList(LinkedList *list)
{
    if (list->head->next == NULL)
    {
        fprintf(stderr, "Cant shift head without other elements\n");
        return NULL;
    }

    // remove head and replace it with next pointer node.
    Node *prev = list->head;
    list->head = list->head->next;


    prev->next = NULL;
    return prev;
}

void popList(LinkedList *list)
{
    return;
}

int sizeOfLinkedList(LinkedList *list)
{
    Node *temp = list->head;
    int size = 0;

    while (temp != NULL)
    {
        if (temp->next != NULL)
            size++;

        temp = temp->next;
    }
    return size;
}

int isEmpty(LinkedList *list) {
    if (list->head->next == NULL)
    {
        return 1;
    } 
    else {
        return 0;
    }
}

void printLinkedList(LinkedList *list)
{
    // Print linked list
    Node *temp = list->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void freeLinkedList(LinkedList *list)
{
    // Free allocated memory
    Node *temp = list->head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}
