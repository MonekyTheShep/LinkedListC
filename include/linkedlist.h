#pragma once

/**
 * @file linkedlist.h
 * @brief Create and modify a linked list.
 */


/**
 * @struct Node
 * @brief A node to be inserted into a linked list.
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * @struct LinkedList
 * @brief The linked list which contains head and tail node. You can traverse the list through the head node.
 */

typedef struct LinkedList {
    Node *head;          
    Node *tail;
} LinkedList;


/**
 * @brief Create a list.
 *
 * Creates a list by allocating a head node and setting the head and tail to default.
 *
 * @param data The data you want to insert into the head.
 * @return An initialized Linked list to insert nodes into.
 */

LinkedList createList(int data);

/**
 * @brief Create a node.
 *
 * A node that is on its own and can be inserted into a list.
 *
 * @param data The data you want to insert into the node.
 * @return A node.
 */

Node *createNode(int data);


/**
 * @brief Insert a node at tail of list.
 *
 * @param list The list you want to insert the node.
 * @param data The data you want to insert into the node.
 * @return A node that points to the node in the list.
 */

Node *insertAtTail(LinkedList *list, int data);

/**
 * @brief Insert a node at head of list.
 *
 * @param list The list you want to insert the node.
 * @param data The data you want to insert into the node.
 * @return A node that points to the node in the list.
 */

Node *insertAtHead(LinkedList *list, int data);

/**
 * @brief Insert a node before a node in a list.
 *
 * @param list The list you want to insert the node.
 * @param data The data you want to insert into the node.
 * @return A node that points to the node in the list.
 */

Node *insertAtNode(LinkedList *list, Node *node, int data);


/**
 * @brief Get the size of a list
 *
 * @param list The list you want to get size of.
 * @return Size of list
 */

int sizeOfLinkedList(LinkedList *list);

/**
 * @brief Get if the list is empty.
 *
 * @param list The list you want to insert the node.
 * @return If the list is empty
 */

int isEmpty(LinkedList *list);


/**
 * @brief Shifts the head acting as FIFO or queue
 *
 * @param list The list you want to shift the head.
 * @return A node that has been removed from the head.
 */

Node *shiftList(LinkedList *list);

/**
 * @brief Shifts the tail acting as LIFO or stack.
 *
 * @param list The list you want to shift the tail.
 * @return A node that has been removed from the head.
 */

Node *popList(LinkedList *list);

/**
 * @brief Removes a node from a list.
 *
 * @param list The list you want to remove a node from.
 * @param node The node you want to remove from the list.
 * @return If the pop has been successful.
 */

int popNode(LinkedList *list, Node **node);

/**
 * @brief Clears a list.
 *
 * @param list The list you want to clear.
 * @return An empty list.
 */

LinkedList clearList(LinkedList *list);

/**
 * @brief Free every node of a list.
 *
 * @param list The list you want to free nodes.
 */

void freeLinkedList(LinkedList *list);

/**
 * @brief Print every node of a list.
 *
 * @param list The list you want print.
 */

void printLinkedList(LinkedList *list);

