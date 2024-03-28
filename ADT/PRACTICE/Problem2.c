// ? Given an array Arr of size N, print second largest distinct element from an array.

//* Example 1:
// ! Input: 
// ! N = 6
// ! Arr[] = {12, 35, 1, 10, 34, 1}
// ! Output: 34
// ! Explanation: The largest element of the 
// ! array is 35 and the second largest element
// ! is 34.

//* Example 2:
// ! Input: 
// ! N = 3
// ! Arr[] = {10, 5, 10}
// ! Output: 5
// ! Explanation: The largest element of 
// ! the array is 10 and the second 
// ! largest element is 5.

/* 
? Your Task:
? You don't need to read input or print anything. Your task is to complete the function print2largest() which takes the array of integers arr and n as parameters and returns an integer denoting the answer. If 2nd largest element doesn't exist then return -1.

! Expected Time Complexity: O(N)
! Expected Auxiliary Space: O(1)

* Constraints:
? 1 ≤ N ≤ 105
? 1 ≤ Arri ≤ 105 
*/

// ********************SOLUTION********************

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int printlargest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;    
}

int search(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == printlargest(arr, n))
        {
            return i;
        }
        
    }
    
}

void indDelete(int arr[], int n)
{
    for (int i = search(arr, n) ; i < n-1; i++)
    {
        arr[i] = arr[i+1];    
    }
    
}

int print2largest(int arr[], int n)
{
    indDelete(arr, n);
    return printlargest(arr, n-1);
}

int print3largest(int arr[], int n)
{
    indDelete(arr, n);
    indDelete(arr, n);
    return printlargest(arr, n-2);
}

int main(){
    system("cls");
    int arr[] = {1, 2, 63, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    printf("%d\n", print3largest(arr, n));
    return 0;
}