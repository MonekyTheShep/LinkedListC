# LinkedListC
Linked List implementation in c

## Example Usage
```c
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

// Check allocation
if (!list.head) {
    printf("Memory allocation failed\n");
    return 1;
}
     

Node *node2 = insertAtHead(&list, 4);


printf("Is list empty: %d\n", isEmpty(&list));

printf("%d\n", list.head->data);
printf("%d\n", list.tail->data);

printLinkedList(&list);

printf("size: %d\n", sizeOfLinkedList(&list));

freeLinkedList(&list);

```
