#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = (2*i) + 1;
	int right = (2*i) + 2;
	
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}
	
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
	printArray(arr, n);
}

void heapSort(int arr[], int n) {
	int i, j;
	
	for(i = (n/2)-1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	
	for(i = n-1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
	printArray(arr, n);
}
