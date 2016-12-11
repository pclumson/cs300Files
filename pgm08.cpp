/*
 * adapted from http://quiz.geeksforgeeks.org/merge-sort/
 */
// PRINCE CLUMSON  12 05 2016 

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

 using namespace std;
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{

    int leftOffset = 0;
    int rightOffset = 0;
    int mergeOffset = l;
    int leftLength = m - l + 1;
    int rightLength =  r - m;
 
    /* create temp arrays */
    int L[leftLength], R[rightLength];
 
    /* Copy data to temp arrays L[] and R[] */
    // copies are needed since arr will be overwritten
    for (int i = 0; i < leftLength; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < rightLength; i++)
        R[i] = arr[m + 1 + i];
 
    /* Merge the temp arrays back into arr[l..r]*/
    while (leftOffset < leftLength && rightOffset < rightLength)
    {
        if (L[leftOffset] <= R[rightOffset])
        {
            arr[mergeOffset] = L[leftOffset];
            leftOffset++;
        }
        else
        {
            arr[mergeOffset] = R[rightOffset];
            rightOffset++;
        }
        mergeOffset++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (leftOffset < leftLength)
    {
        arr[mergeOffset] = L[leftOffset];
        leftOffset++;
        mergeOffset++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (rightOffset < rightLength)
    {
        arr[mergeOffset] = R[rightOffset];
        rightOffset++;
        mergeOffset++;
    }  
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 
 //A FUNCTION to sort an array using  INSERTION SORT
 
    void insertionSort(int arr[], int size)
       {
          int j, temp;
          
             for (int i =0; i< size; i++)
               {
                   j= i ;
                   while (j>0 && arr[j] < arr[j-1])
                   {
                     temp = arr[j];
                     arr[j] = arr[j-1];
                     arr[j-1] = temp;
                     j--;
                     
                   
                   }
               
               }
       
       
       }
 
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7,20,25,21,24,65,52,38,14,26,41,68,77,93,97};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is :  \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is  : \n");
    printArray(arr, arr_size);
    
    cout<< "########################################################"<<endl;
    
    cout<< "Here is the insertion sort array function implementation : "<<endl;
    
    int arr2[] = {13, 11, 12, 93, 6, 7,20,25,21,24,65,52,97,14,26,41,68,77,5,38};
    
 
    printf("Given array 1 is : \n");
    printArray(arr2, arr_size);
 
    
    insertionSort(arr2, arr_size);
    
    printf("\nSorted array 1 is :\n");
    printArray(arr2, arr_size);
    
    cout<< "########################################################"<<endl;
     int item;
     int i;
     cout << "Enter the item you want to find: ";
      cin >> item;
    
    
    i = 0;
    while ( i < sizeof( arr ) / sizeof( *arr ) && arr[i] != item ) i++;

    if( i  != sizeof( arr ) / sizeof( *arr ) )
    {
        cout << "Item is found at location " << i+1 << endl;
    }
    else
    {
        cout << "Not exist!" << endl;
    }
    
    
    return 0;
}
