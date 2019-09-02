#include <stdlib.h> 
#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
long long int k = 0;
void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) { 
	k++;
	int st = 0;
	for (int i = l; i < r; ++i)
	{
		if(arr[i] > arr[i + 1]){
			st = 1;
			break;
		}
	}
	if(st == 0)
		return;
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 

        int m = 0;
        if( (l + r) % 2 == 0)
        	m = l+(r-l)/2 - 1;
        else
        	m = l+(r-l)/2;
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) { 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main(int argc, char const *argv[])
{
 
    ifstream test_in(argv[1]);    /* This stream reads from test's input file   */
    ifstream test_out(argv[2]);   /* This stream reads from test's output file  */
    ifstream user_out(argv[3]);   /* This stream reads from user's output file  */
 
    long long int n, s;
    test_in >> n >> s;
    
    int arr[n];
    for (int i = 0; i < n; ++i){
        user_out >> arr[i];
    }
 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    mergeSort(arr, 0, arr_size - 1); 

    if(s == k)
        return 0;
    else
        return 1; 
}