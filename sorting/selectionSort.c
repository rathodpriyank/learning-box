#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void selectionSort(int arr[], int n) {
	int i, j = 0;
	for(i = 0; i < n - 1; i++)
		for(j = i+1; j < n; j++)
			if(arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
}
