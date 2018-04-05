

#define min(x, y) 	x < y ? x : y; 

void swap(int *a, int *b);
void printArray(int arr[], int n);

void bubbleSort(int arr[], int n);
void bubbleSortRecursive(int arr[], int n);

void insersionSort(int arr[], int n);
void insertionSortRecursive(int arr[], int n);

void selectionSort(int arr[], int n);

void mergeSort(int arr[], int start, int end);
void mergeSortRecursive(int arr[], int start, int end);

void quickSort(int arr[], int start, int end);
void quickSortRecursive(int arr[], int start, int end);

void heapSort(int arr[], int n);
