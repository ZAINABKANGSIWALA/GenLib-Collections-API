#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "tm_avl.h"

// Comparison function for integers
int intCompare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y); // returns 1, 0, or -1
}

// Callback function for traversal
void printInt(void *data)
{
    printf("%d ", *(int *)data);
}

int main()
{
    bool success;

    // Create AVL tree
    AVLTree *tree = createAVLTree(intCompare, &success);
    if (!success || !tree)
    {
        printf(" Failed to create AVL tree\n");
        return 0;
    }
    printf(" AVL tree created successfully\n");

    // Insert elements
    int *nums[7];
    int values[] = {20, 4, 15, 70, 50, 100, 10};
    for (int i = 0; i < 7; i++)
    {
        nums[i] = (int *)malloc(sizeof(int));
        *nums[i] = values[i];
        insertIntoAVLTree(tree, nums[i], &success);
        if (success) printf("Inserted %d\n", *nums[i]);
    }

    // Traversals
    printf("In-order traversal: ");
    inOrderTraversal(tree, printInt);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(tree, printInt);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(tree, printInt);
    printf("\n");

    // Search
    int key = 15;
    int *found = (int *)searchInAVLTree(tree, &key, &success);
    if (success) printf(" Found %d in AVL tree\n", *found);
    else printf(" %d not found\n", key);

    // Remove a node
    int delKey = 20;
    removeFromAVLTree(tree, &delKey, &success);
    if (success) printf(" Removed %d from AVL tree\n", delKey);
    else printf(" Failed to remove %d\n", delKey);

    printf("In-order after deletion: ");
    inOrderTraversal(tree, printInt);
    printf("\n");

    // Clear tree
    clearAVLTree(tree);
    printf(" AVL tree cleared\n");

    // Destroy tree
    destroyAVLTree(tree);
    printf(" AVL tree destroyed\n");

    // Free allocated integers
    for (int i = 0; i < 7; i++)
        free(nums[i]);

    return 0;
}
