#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
	SELECTION_SORT,
	INSERSION_SORT,
	BUBBLE_SORT,
} sort_techniques;

uint64_t GetTimeStamp() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(uint64_t)1000000+tv.tv_usec;
}

void print (int arr[], int n, char *msg) {
    int i = 0;
    printf("--------------------------------\n");
    printf("%s, Size of Array is : %d\n", msg, n);
    for(i = 0; i < n; i++)
        printf("Array index %d is : %d\n", i, arr[i]);
    printf("end of %s\n", msg);
    printf("--------------------------------\n");
}

void swap(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void insertElement(int arr[], int *n, int location, int value) {
  int temp = *n;

  arr = realloc(arr, 12);

   while( temp >= location ) {
        arr[temp+1] = arr[temp];
        temp--;
    }
    arr[location] = value;
}

void deleteElement(int arr[], int* n, int location) {
  int temp = *n;
   while( location < temp ) {
        arr[location-1] = arr[location]; 
        location++;
    }
}

bool searchElement (int arr[], int n, int value) {
    int i = 0;
    for(i = 0; i < n; i++) {
        if (arr[i] == value)
            return 1;
    }
    return 0;
}

void updateElement(int arr[], int *n, int location, int value) {
   int i = 0;
   
   while ( location < *n ) {
       *n--;
   }
   arr[location] = value;
}

void bubbleSort(int arr[], int n) {
	int i = 0, j = 0, flag = 0;
	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

void selectionSort(int arr[], int n) {
	int i = 0, j = 0;
	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n ; j++) {
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}

void main () {
	int option = -1;
	int i = 0, j = 0, k = 0;
	uint64_t t1 = 0, t2 = 0;
	int sample_array[] = { 5, 25, 20, 43, 35, 82, 59, 22, 12 };
	int sample_array_len = sizeof(sample_array);
	int array_length = sizeof(sample_array) / sizeof(sample_array[0]);
	int *array = malloc(sample_array_len);
	
	for(i = 0; i < array_length; i++)
		array[i] = sample_array[i];

    /* Traverse − print all the array elements one by one. */
    print(array, array_length, "Traversal");
	
    /* Insertion − Adds an element at the given index */
    array_length++;
    insertElement(array, &array_length, 3, 18);
    print(array, array_length, "Insertion");
    
	/* Deletion − Deletes an element at the given index */
    deleteElement(array, &array_length, 2);
    array_length--;
    print(array, array_length, "Deletion");

    /* Search − Searches an element using the given index or by the value */
    printf("Value is present : %s\n", searchElement(array, array_length, 20) ? "Yes" : "No");
    
    /* Update − Updates an element at the given index */
    updateElement(array, &array_length, 3, 99);
    print(array, array_length, "Update");
    
    
   option = BUBBLE_SORT;
   switch (option) 
   {
	   case SELECTION_SORT:
			/* selectionSort */
			t1 = GetTimeStamp();
			selectionSort(array, array_length);
			t2 = GetTimeStamp();
			print(array, array_length, "Selection Sort");
			printf("\n[selectionSort] Total time was : %lu\n", (t2-t1));
			break;
		
		case BUBBLE_SORT: 
			/* bubbleSort */
			t1 = GetTimeStamp();
			bubbleSort(array, array_length);
			t2 = GetTimeStamp();
			print(array, array_length, "Bubble Sort");
			printf("\n[bubbleSort] Total time was : %lu\n", (t2-t1));
	}
    
}
