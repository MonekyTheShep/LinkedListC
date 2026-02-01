# LinkedListC
Linked List implementation in c


## linkedlist.h

### Structs:

```typedef struct Node``` Stores data and next node in list.

```typedef struct LinkedList``` Stores the head and tail of a list.

### Functions:

```LinkedList createList(int data)``` Returns list with head initialized.

```Node *createNode(int data)``` Create node to insert into the list.

```Node *insertAtTail(LinkedList *list, int data)``` Insert node at the tail of a list.

```Node *insertAtHead(LinkedList *list, int data)``` Insert node at the head of a list.

```Node *insertAtNode(LinkedList *list, Node *node, int data)``` Insert before a node in list.

```int sizeOfLinkedList(LinkedList *list)``` Returns the size of the list

```int isEmpty(LinkedList *list)``` Checks if list is empty

```Node *shiftList(LinkedList *list)``` Returns the head and removes it (FIFO) acts as a queue

```Node *popList(LinkedList *list)``` Not implemented

```int popNode(LinkedList *list, Node **node)``` Removes a node using a pointer to a node from the list.

```void freeLinkedList(LinkedList *list)``` Frees every element of linked list from memory

```void printLinkedList(LinkedList *list)``` Prints every element of linked list


## Example Usage
```c
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void)
{
    LinkedList list;
    list = createList(0);

    for (int i = 1; i < 9; ++i) {
        Node *node = insertAtTail(&list, i);
    }  

    printf("Is list empty: %d\n", isEmpty(&list));
    printLinkedList(&list);
    printf("size: %d\n", sizeOfLinkedList(&list));

    printf("%d\n", list.head->data);
    printf("%d\n", list.tail->data);

    freeLinkedList(&list);
}
```
