#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "tm_graph.h"
#include "tm_sll.h"

// Comparison function for integers
int intCompare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

// Callback to print adjacency list
void printAdjList(SinglyLinkedList *list)
{
    int size = getSizeOfSinglyLinkedList(list);
    for (int i = 0; i < size; i++)
    {
        GraphNode *v = (GraphNode *)getFromSinglyLinkedList(list, i, NULL);
        printf("%d ", *(int *)v->data);
    }
    printf("\n");
}

int main()
{
    bool success;

    // Create undirected graph
    Graph *graph = createGraph(intCompare, false, &success);
    if (!success || !graph)
    {
        printf(" Failed to create graph\n");
        return 0;
    }
    printf(" Graph created successfully\n");

    // Add vertices
    int *nums[5];
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        nums[i] = (int *)malloc(sizeof(int));
        *nums[i] = values[i];
        addVertex(graph, nums[i], &success);
        if (success) printf("Added vertex %d\n", *nums[i]);
    }

    // Add edges
    addEdge(graph, nums[0], nums[1], &success); // 1-2
    addEdge(graph, nums[0], nums[2], &success); // 1-3
    addEdge(graph, nums[1], nums[3], &success); // 2-4
    addEdge(graph, nums[3], nums[4], &success); // 4-5
    printf(" Edges added\n");

    // Print adjacency lists
    for (int i = 0; i < 5; i++)
    {
        if (hasVertex(graph, nums[i]))
        {
            SinglyLinkedList *adj = getAdjacencyList(graph, nums[i], &success);
            if (success)
            {
                printf("Vertex %d: ", *nums[i]);
                printAdjList(adj);
            }
        }
    }

    // Remove edge 1-3
    removeEdge(graph, nums[0], nums[2], &success);
    printf(" Removed edge 1-3\n");

    // Print adjacency list of 1
    SinglyLinkedList *adj1 = getAdjacencyList(graph, nums[0], &success);
    if (success)
    {
        printf("Vertex %d after edge removal: ", *nums[0]);
        printAdjList(adj1);
    }

    // Remove vertex 4
    removeVertex(graph, nums[3], &success);
    printf(" Removed vertex 4\n");

    // Print adjacency lists after removal
    for (int i = 0; i < 5; i++)
    {
        if (hasVertex(graph, nums[i]))
        {
            SinglyLinkedList *adj = getAdjacencyList(graph, nums[i], &success);
            if (success)
            {
                printf("Vertex %d: ", *nums[i]);
                printAdjList(adj);
            }
        }
    }

    // Clear and destroy graph
    clearGraph(graph);
    destroyGraph(graph);
    printf(" Graph cleared and destroyed\n");

    // Free allocated integers
    for (int i = 0; i < 5; i++)
        free(nums[i]);

    return 0;
}
