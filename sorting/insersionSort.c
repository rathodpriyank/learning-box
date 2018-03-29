#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void insersionSort(int arr[], int n) {
	int i, j, key = 0;
	
	for(i = 1; i < n; i++) {
		
		key = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void insertionSortRecursive(int arr[], int n) {
	if(n == 1)
		return;
	
	insertionSortRecursive(arr, n-1);
	
	int key = arr[n-1];
	int i = n - 2;
	
	while (i >= 0 && arr[i] > key) {
		arr[i+1] = arr[i];
		i--;
	} 
	arr[i+1] = key;
}
