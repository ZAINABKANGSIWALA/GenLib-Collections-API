#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "tm_map.h"

// Comparison function for integer keys
int intCompare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

// Helper function to print integer map
void printIntMap(Map *map)
{
    int size = getSizeOfMap(map);
    printf("Map has %d entries:\n", size);
    for (int i = 0; i < size; i++)
    {
        MapEntry *entry = (MapEntry *)getFromSinglyLinkedList(map->list, i, NULL);
        printf("%d -> %d\n", *(int *)entry->key, *(int *)entry->value);
    }
    printf("\n");
}

int main()
{
    bool success;

    // Create a map
    Map *map = createMap(intCompare, &success);
    if (!success)
    {
        printf(" Failed to create map\n");
        return 0;
    }
    printf(" Map created successfully\n");

    // Add key-value pairs
    for (int i = 1; i <= 5; i++)
    {
        int *key = (int *)malloc(sizeof(int));
        int *value = (int *)malloc(sizeof(int));
        *key = i;
        *value = i * 10;
        put(map, key, value, &success);
        if (success) printf("Added %d -> %d\n", *key, *value);
    }

    printf("\nInitial map:\n");
    printIntMap(map);

    // Update a value
    printf("Updating key 3 to value 999\n");
    int key3 = 3;
    int val999 = 999;

    // Find actual pointer used for key 3
    int size = getSizeOfMap(map);
    for (int i = 0; i < size; i++)
    {
        MapEntry *entry = (MapEntry *)getFromSinglyLinkedList(map->list, i, NULL);
        if (*(int *)entry->key == key3)
        {
            put(map, entry->key, &val999, &success);
            break;
        }
    }

    printf("\nAfter updating key 3:\n");
    printIntMap(map);

    // Get value of a key
    int keyToGet = 4;
    void *val = NULL;
    for (int i = 0; i < size; i++)
    {
        MapEntry *entry = (MapEntry *)getFromSinglyLinkedList(map->list, i, NULL);
        if (*(int *)entry->key == keyToGet)
        {
            val = get(map, entry->key, &success);
            break;
        }
    }
    if (success) printf("Value for key %d: %d\n", keyToGet, *(int *)val);

    // Remove a key
    printf("Removing key 2\n");
    int key2 = 2;
    for (int i = 0; i < size; i++)
    {
        MapEntry *entry = (MapEntry *)getFromSinglyLinkedList(map->list, i, NULL);
        if (*(int *)entry->key == key2)
        {
            removeKey(map, entry->key, &success);
            break;
        }
    }

    printf("\nAfter removing key 2:\n");
    printIntMap(map);

    // Clear map
    clearMap(map);
    printf("Map cleared. Size now: %d\n", getSizeOfMap(map));

    // Destroy map
    destroyMap(map);
    printf("Map destroyed\n");

    return 0;
}
