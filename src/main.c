#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


// Node *node = shiftList(&list);
// node = insertAtTail(&list, node->data);

int main(void) {
    int i = 0;
    LinkedList list;
    for (; i < 9; ++i) {
        if (i == 0) {
            list = createList(i);
            continue;
        }
        // Check allocation
        Node *node = insertAtTail(&list, i);
        if (!node) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }  

    Node *node2 = NULL;

    popNode(&list, node2);


    // Check allocation
    if (!list.head) {
        printf("Memory allocation failed\n");
        return 1;
    }
     

    printf("%d\n", list.head->data);
    printf("%d\n", list.tail->data);

    printLinkedList(&list);

    printf("size: %d\n", sizeOfLinkedList(&list));

    freeLinkedList(&list);

    return 0;
}
