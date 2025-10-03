#include <stdio.h>
#include "tm_bubble_sort.h"

int main()
{
    int arr[] = {5, 3, 9, 1, 7};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (size_t i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    bubbleSort(arr, n, sizeof(int), intCompare);

    printf("After sorting:  ");
    for (size_t i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    float farr[] = {3.2, 1.5, 4.8, 0.5};
    size_t fn = sizeof(farr) / sizeof(farr[0]);

    printf("Before float sort: ");
    for (size_t i = 0; i < fn; i++) printf("%.2f ", farr[i]);
    printf("\n");

    bubbleSort(farr, fn, sizeof(float), floatCompare);

    printf("After float sort:  ");
    for (size_t i = 0; i < fn; i++) printf("%.2f ", farr[i]);
    printf("\n");

    return 0;
}
