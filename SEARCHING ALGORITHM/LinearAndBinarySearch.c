#include <stdio.h> //In place of <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// int linearSearch(int arr[], int size, int element){
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == element)
//         {
//             return i;
//         }
//     }
//     return -1;
// }


int linearSearch(int *arr, int size, int element){
    for (int i = 0; i < size; i++)
    {
        if (*(arr+i) == element)
        {
            return i;
        }
    }
    return 0;
}

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return 0;
    
}

int main(){
    system("cls");

    // ! 👇🏻 CODE FOR THE LINER SEARCH
    
    
    // int arr[100] = {1, 3, 56, 28, 295, 2, 30, 517, 3, 2038};
    // int size = sizeof(arr)/sizeof(int);
    // int element;

    // printf("Which element will you wanna search???\n");
    // scanf("%d", &element);
    // // ******REMEMBER THIS FORMULA FOR FINDING THE SIZE OF ANY ARRAY******
    
    // int searchIndex = linearSearch(arr, size, element);



    // ! CODE FOR THE BINARY SEARCH PROGRAM
    
    int arr[] = {1, 3, 56, 285, 295, 299, 300, 517, 533, 2038};
    // ? THE UTMOST CONDITION FOR THE BINARY SEARCH IS THAT THE ARRAY SHOULD BE SORTED, i.e. , THE ELEMENTS SHOULD BE ARRANGED IN A INCREASING ORDER
    int size = sizeof(arr)/sizeof(int);
    int element;

    printf("Which element will you wanna search???\n");
    scanf("%d", &element);
    // ******REMEMBER THIS FORMULA FOR FINDING THE SIZE OF ANY ARRAY******
    
    int searchIndex = binarySearch(arr, size, element);
    
    if (searchIndex != 0)
    {
        printf("The element %d was found at index %d\n", element, searchIndex);
    }
    else
    {
        printf("The element %d is not present in the array\n", element);
    }
    return 0;
}