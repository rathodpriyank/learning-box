#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void selectionSort(int A[], int n) {
    int i = 0; int j = 0; int temp = -1; 
    for(i = 0; i < n-1; i++) {
        for(j = i + 1; j < n; j++) {
            if (A[i] > A[j]) 
				swap(&A[i], &A[j]);
        }
    }
}

void bubbleSort(int A[], int n) {
    int i = 0; int j = 0; int temp = 0; int flag = 0;
    for(i = 0; i < n - 1; i++) {
//        flag = 0;
        for(j = 0; j < n - i - 1; j++) {
            if(A[j] > A[j+1]) {
				swap(&A[j], &A[j+1]);
  //              flag = 1;
            }
        }
    //    if(flag == 0)
      //      break;
    }   
}

void insertionSort(int A[], int n) {
    int i = 0; int pos = 0; int temp = -1;
    for(i = 0; i < n - 1; i++) {
           temp = A[i];
           pos = i;
        while(pos > 0 && A[pos - 1] > temp) {
            A[pos] = A[pos - 1];
            pos = pos - 1;
        }
        A[pos] = temp;
    }
}

void merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void mergeSort(int *A, int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	mergeSort(L,mid);  // sorting the left subarray
	mergeSort(R,n-mid);  // sorting the right subarray
	merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}

int partition( int a[], int l, int r) {
   int pivot, i, j;
   pivot = a[l];
   i = l; j = r+1;
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
		swap(&a[i], &a[j]);
   }
	swap(&a[l], &a[j]);
   return j;
}

void quickSort(int A[], int m, int n) {
	int part = -1;
	if (m < n) {
		part = partition(A, m, n);
		quickSort(A, m, part - 1);
		quickSort(A, part + 1, n);
	}
}

uint64_t GetTimeStamp() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(uint64_t)1000000+tv.tv_usec;
}

int main(void)
{
    int i = 0;
    unsigned long long t1, t2; 
    int A[] = {20,3,15,5,4,10,25};
	int n = sizeof(A)/sizeof(A[0]) - 1;
	int *B = malloc(sizeof(int)*n);
	int *C = malloc(sizeof(int)*n);
	int *D = malloc(sizeof(int)*n);
	int *E = malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

    t1 = GetTimeStamp();
    selectionSort(A, n);
    t2 = GetTimeStamp();
    for(i=0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n[selectionSort] Total time was : %llu\n", (t2-t1));
    
    t1 = GetTimeStamp();
    bubbleSort(B, n);
    t2 = GetTimeStamp();
    for(i=0; i < n; i++)
        printf("%d ", B[i]);
    printf("\n[bubbleSort] Total time was : %llu\n", (t2-t1));
    
    t1 = GetTimeStamp();
    insertionSort(C, n);
    t2 = GetTimeStamp();
    for(i=0; i < n; i++)
        printf("%d ", C[i]);
    printf("\n[insertionSort] Total time was : %llu\n", (t2-t1));
    
    t1 = GetTimeStamp();
    mergeSort(D, n);
    t2 = GetTimeStamp();
    for(i=0; i < n; i++)
        printf("%d ", D[i]);
    printf("\n[mergeSort] Total time was : %llu\n", (t2-t1));

     t1 = GetTimeStamp();
     quickSort(E,0, n);
     t2 = GetTimeStamp();
     for(i=0; i < n; i++)
         printf("%d ", E[i]);
     printf("\n[quickSort] Total time was : %llu\n", (t2-t1));

    return 0;
}
