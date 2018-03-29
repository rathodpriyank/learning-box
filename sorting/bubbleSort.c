#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void bubbleSort(int arr[], int n) {
	int i, j = 0;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - i - 1; j++)
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

void bubbleSortRecursive(int arr[], int n) {
	if (n == 1)
		return;
		
	int i = 0;
	for(i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i+1]) {
			swap(&arr[i], &arr[i+1]);
		}
	}
	bubbleSortRecursive(arr, n-1);
}
