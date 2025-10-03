#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "tm_queue.h"

int main()
{
    bool success;
    Queue *queue = createQueue(&success);
    if (!success || queue == NULL)
    {
        printf(" Failed to create queue\n");
        return 0;
    }
    printf(" Queue created successfully\n");

    // Push elements (dynamic allocation since void*)
    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));
    int *c = (int *)malloc(sizeof(int));
    *a = 10; *b = 20; *c = 30;

    addToQueue(queue, a, &success);
    addToQueue(queue, b, &success);
    addToQueue(queue, c, &success);
    printf(" Enqueued 3 elements (10, 20, 30)\n");

    // Check size
    printf("Queue size: %d (expected 3)\n", getSizeOfQueue(queue));

    // Check front element
    int *front = (int *)elementAtFrontOfQueue(queue, &success);
    if (success) printf("Front element: %d (expected 10)\n", *front);

    // Dequeue elements
    int *d1 = (int *)removeFromQueue(queue, &success);
    if (success) printf("Dequeued: %d (expected 10)\n", *d1);
    free(d1);

    int *d2 = (int *)removeFromQueue(queue, &success);
    if (success) printf("Dequeued: %d (expected 20)\n", *d2);
    free(d2);

    int *d3 = (int *)removeFromQueue(queue, &success);
    if (success) printf("Dequeued: %d (expected 30)\n", *d3);
    free(d3);

    // Check empty
    printf("Is queue empty? %s (expected YES)\n", isQueueEmpty(queue) ? "YES" : "NO");

    // Test clear (should not fail even if empty)
    clearQueue(queue);
    printf(" Queue cleared successfully\n");

    // Destroy queue
    destroyQueue(queue);
    printf(" Queue destroyed successfully\n");

    return 0;
}
