#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


// Node *node = shiftList(&list);
// node = insertAtTail(&list, node->data);

int main(void) {
    int i;
    LinkedList list;
    for (i = 0; i < 9; ++i) {
        if (i == 0) {
            list = createList(i);
            continue;
        }
        // Check allocation
        Node *node = insertAtTail(&list, i);
    }  

    printf("Is list empty: %d\n", isEmpty(&list));
    printLinkedList(&list);
    printf("size: %d\n", sizeOfLinkedList(&list));

    printf("%d\n", list.head->data);
    printf("%d\n", list.tail->data);

    freeLinkedList(&list);
    return 0;
}
