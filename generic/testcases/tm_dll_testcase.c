#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "tm_dll.h"

int main()
{
    bool success;
    DoublyLinkedList *list = createDoublyLinkedList(&success);
    if(!success || list == NULL)
    {
        printf(" Failed to create DoublyLinkedList\n");
        return 0;
    }
    printf(" DoublyLinkedList created\n");

    // Insert integers into the list
    int *a = (int*)malloc(sizeof(int));
    int *b = (int*)malloc(sizeof(int));
    int *c = (int*)malloc(sizeof(int));
    int *d = (int*)malloc(sizeof(int));
    *a = 10; *b = 20; *c = 30; *d = 40;

    addToDoublyLinkedList(list, a, &success);
    addToDoublyLinkedList(list, b, &success);
    addToDoublyLinkedList(list, c, &success);

    printf(" Added 3 elements, size = %d\n", getSizeOfDoublyLinkedList(list));

    // Insert at index 1
    insertIntoDoublyLinkedList(list, 1, d, &success);
    printf("Inserted 40 at index 1, size = %d\n", getSizeOfDoublyLinkedList(list));

    // Print all values
    printf("Current List: ");
    for(int i=0; i<getSizeOfDoublyLinkedList(list); i++)
    {
        int *val = (int*)getFromDoublyLinkedList(list, i, &success);
        printf("%d ", *val);
    }
    printf("\n");

    // Remove element at index 2
    int *removed = (int*)removeFromDoublyLinkedList(list, 2, &success);
    if(success)
    {
        printf(" Removed element at index 2: %d\n", *removed);
        free(removed); // free manually
    }

    // Print after removal
    printf("List after removal: ");
    for(int i=0; i<getSizeOfDoublyLinkedList(list); i++)
    {
        int *val = (int*)getFromDoublyLinkedList(list, i, &success);
        printf("%d ", *val);
    }
    printf("\n");

    // Create another list to append
    DoublyLinkedList *list2 = createDoublyLinkedList(&success);
    int *x = (int*)malloc(sizeof(int));
    int *y = (int*)malloc(sizeof(int));
    *x = 100; *y = 200;
    addToDoublyLinkedList(list2, x, &success);
    addToDoublyLinkedList(list2, y, &success);

    appendToDoublyLinkedList(list, list2, &success);
    printf(" Appended list2, new size = %d\n", getSizeOfDoublyLinkedList(list));

    printf("Final List: ");
    for(int i=0; i<getSizeOfDoublyLinkedList(list); i++)
    {
        int *val = (int*)getFromDoublyLinkedList(list, i, &success);
        printf("%d ", *val);
    }
    printf("\n");

    // Cleanup
    clearDoublyLinkedList(list);
    destroyDoublyLinkedList(list);
    destroyDoublyLinkedList(list2);

    printf(" All memory freed\n");
    return 0;
}
