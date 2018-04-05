#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "common.h"

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swapA(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void printArray(int arr[], int n) {
	int i = 0;
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void main () {
	int option = -1;
	volatile bool whileLoop = true;
	int array[] = { 76, 2, 34, 22, 87, 55, 45, 98, 23, 52 } ;
	int n = sizeof(array) / sizeof(array[0]);
	printArray(array, n);
	
	while(whileLoop) {
		printf("------------------------------------\n");
		printf("Sorting Methods\n");
		printf("0. Print current Array\n");
		printf("1. Bubble Sort\n");
		printf("2. Bubble Sort Recursive\n");
		printf("3. Selection Sort\n");
		printf("4. Insersion Sort\n");
		printf("5. Insersion Sort Recursive\n");
		printf("6. Merge Sort\n");
		printf("7. Merge Sort Recursive\n");
		printf("8. Quick Sort \n");
		printf("9. Quick Sort Recursive\n");
		printf("10. Heap Sort\n");
		printf("99. Exit\n");
		printf("------------------------------------\n");
		printf("Select the option : ");
		scanf("%2d", &option);
		
		switch(option) {
			case 0:
					printf("Printing an array\n");
					printArray(array, n);
					break;
			case 1:
					printf("Doing Bubble Sort\n");
					bubbleSort(array, n);
					break;
			case 2:
					printf("Doing Bubble Sort Recursive \n");
					bubbleSortRecursive(array, n);
					break;
			case 3:
					printf("Doing Selection Sort \n");
					selectionSort(array, n);
					break;
			case 4:
					printf("Doing Insersion Sort \n");
					insersionSort(array, n);
					break;
			case 5:
					printf("Doing Insersion Sort Recursive \n");
					insertionSortRecursive(array, n);
					break;
			case 6:
					printf("Doing merge Sort \n");
					mergeSort(array, 0, n);
					break;
			case 7:
					printf("Doing merge Sort Recursive\n");
					mergeSortRecursive(array, 0, n);
					break;
			case 8:
					printf("Doing quick Sort\n");
					quickSort(array, 0, n);
					break;
			case 9:
					printf("Doing quick Sort Recursive\n");
					quickSortRecursive(array, 0, n);
					break;
			case 10:
					printf("Doing Heap Sort\n");
					heapSort(array, n);
					break;
			case 99:
					whileLoop = false;
					break;
			default:
					printf("Invalid Option\n");
		}
		if (option)
			printArray(array, n);
	}
	
}
