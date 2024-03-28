#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void traverse(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void bubbSort(int arr[], int size)
{
    int temp;

    for (int i = 0; i < size-1; i++)  // ! Number of passes = size-1
    {

        printf("Working on the pass number %d\n", i+1);

        for (int j = 0; j < size-i-1; j++)  // ! Number of possible comparisons = size-i-1
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbSort_Adaptive(int arr[], int size)
{
    int temp;
    int isSorted = 0; // ! Flag Variable to denote that the Array is not sorted

    for (int i = 0; i < size-1; i++)  // ! Number of passes = size-1
    {

        printf("Working on the pass number %d\n", i+1);
        isSorted = 1; // ! It Remains 1 only when the inner for() loop has ended, otherwise it becomes 0...

        for (int j = 0; j < size-i-1; j++)  // ! Number of possible comparisons = size-i-1
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }

        if (isSorted == 1)
        {
            return;
        }
    }
}

void main(){

    system("cls");
    // int arr[] = {12, 54, 65, 7, 23, 9};
    // int arr[] = {1, 4, 5, 7, 8, 9};
    int n = 9;
    int arr[] = {121, 547, 205, 17, 48, 989, 10, 27, 57};

    printf("Printing the array before swapping\n");
    traverse(arr, n);

    bubbSort_Adaptive(arr, n);
    // bubbSort(arr, n);

    printf("Printing the array after swapping\n");
    traverse(arr, n);
}