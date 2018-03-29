#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"


static void merge(int arr[], int start, int middle, int end) {
	
	int i, j, k;
	int n1 = middle - start + 1;
	int n2 = end - middle;
	
	int L[n1], R[n2];
	
	for(i = 0; i < n1; i++)
		L[i] = arr[start + i];
	
	for(j = 0; j < n2; j++)
		R[j] = arr[middle + j + 1];
	
	i = j = 0;
	k = start;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int start, int end) {
	if ( start < end ) {
		int middle  = start + (end-start)/2;
		mergeSort(arr, start, middle);
		mergeSort(arr, middle+1, end);
		merge(arr, start, middle, end);
	}
}

void mergeSortRecursive(int arr[], int start, int end) {
	int i, j;
	for(i = 1; i <= end - 1; i = i * 2) {
		for(j = 0; j < end - 1; j += i * 2) {
			int left_index  = j + i - 1;
			int right_index = min((j + (2*i) - 1), end-1);
			merge(arr, j, left_index, right_index);
		}
	}
}
