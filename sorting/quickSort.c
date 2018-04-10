#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int i = start - 1;
	int j;
	
	for(j = start; j <= end - 1; j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[end]);
	return (i+1);
}

void quickSort(int arr[], int start, int end) {
	if ( start < end ) {
		int pi  = partition(arr, start, end);
		quickSort(arr, start, pi - 1);
		quickSort(arr, pi + 1, end);
	}
}

void quickSortRecursive(int arr[], int start, int end) {
	int tempArray[end - start + 1];
	int value = -1;
	
	tempArray[ ++value ] = start;
	tempArray[ ++value ] = end;
	
	while( value >= 0) {
		
		end = tempArray [ value-- ];
		start = tempArray [ value-- ];
		
		int pi = partition (arr, start, end);
		
		if ( pi-1 > start) {
			tempArray [ ++value ] = start;
			tempArray [ ++value ] = pi - 1;
		}
		
		if ( pi+1 < end) {
			tempArray [ ++value ] = pi + 1;;
			tempArray [ ++value ] = end;
			 
		}
	}
}
