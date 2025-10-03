#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "tm_sll.h"   // make sure this has struct definitions

// Helper function to print list contents
void printList(SinglyLinkedList *list)
{
    int i;
    bool success;
    printf("List(size=%d): ", getSizeOfSinglyLinkedList(list));
    for(i=0; i<getSizeOfSinglyLinkedList(list); i++)
    {
        int *value = (int *)getFromSinglyLinkedList(list, i, &success);
        if(success) printf("%d ", *value);
    }
    printf("\n");
}

int main()
{
    bool success;
    SinglyLinkedList *list = createSinglyLinkedList(&success);
    if(!success || list==NULL)
    {
        printf("Failed to create list\n");
        return 0;
    }
    printf("Created list successfully!\n");

    // Add some integers
    int a=10, b=20, c=30, d=40;
    addToSinglyLinkedList(list, &a, &success);
    addToSinglyLinkedList(list, &b, &success);
    addToSinglyLinkedList(list, &c, &success);
    printf("After adding 10,20,30:\n");
    printList(list);

    // Insert at start
    insertIntoSinglyLinkedList(list, 0, &d, &success);
    printf("After inserting 40 at index 0:\n");
    printList(list);

    // Remove element
    int *removed = (int *)removeFromLinkedList(list, 2, &success);
    if(success) printf("Removed element: %d\n", *removed);
    printList(list);

    // Append another list
    SinglyLinkedList *list2 = createSinglyLinkedList(&success);
    int e=50, f=60;
    addToSinglyLinkedList(list2, &e, &success);
    addToSinglyLinkedList(list2, &f, &success);
    printf("Second list before append:\n");
    printList(list2);

    appendToSinglyLinkedList(list, list2, &success);
    printf("After appending second list:\n");
    printList(list);

    // Clear list
    clearSinglyLinkedList(list);
    printf("After clearing list:\n");
    printList(list);

    // Destroy both
    destroySinglyLinkedList(list);
    destroySinglyLinkedList(list2);
    printf("Lists destroyed.\n");

    return 0;
}
