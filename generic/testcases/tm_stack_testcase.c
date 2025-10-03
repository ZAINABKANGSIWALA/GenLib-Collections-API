#include <stdio.h>
#include <stdlib.h>
#include "tm_stack.h"

int main()
{
    bool success;
    Stack *stack = createStack(&success);
    if (!success || stack == NULL)
    {
        printf(" Failed to create stack\n");
        return 0;
    }
    printf("Stack created successfully\n");

    // Push some integers (dynamic allocation since we use void *)
    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));
    int *c = (int *)malloc(sizeof(int));
    *a = 10; *b = 20; *c = 30;

    pushOnStack(stack, a, &success);
    pushOnStack(stack, b, &success);
    pushOnStack(stack, c, &success);

    printf("Pushed 3 elements (10,20,30)\n");

    // Check size
    printf("Stack size: %d (expected 3)\n", getSizeOfStack(stack));

    // Check top
    int *top = (int *)elementAtTopOfStack(stack, &success);
    if (success) printf("Top element: %d (expected 30)\n", *top);

    // Pop elements
    int *p1 = (int *)popFromStack(stack, &success);
    if (success) printf("Popped: %d (expected 30)\n", *p1);
    free(p1);

    int *p2 = (int *)popFromStack(stack, &success);
    if (success) printf("Popped: %d (expected 20)\n", *p2);
    free(p2);

    int *p3 = (int *)popFromStack(stack, &success);
    if (success) printf("Popped: %d (expected 10)\n", *p3);
    free(p3);

    // Check empty
    printf("Is stack empty? %s (expected YES)\n", isStackEmpty(stack) ? "YES" : "NO");

    // Destroy stack
    destroyStack(stack);
    printf(" Stack destroyed successfully\n");

    return 0;
}
