#include <stdio.h>
//#define N 10 
int r,s,tmp;
#define SWAP(r,s) {tmp=r; r=s; s=tmp;}// while(0)
int arr[10] = {5,2,6,0,11,7,6,7,4,2}; 
 
void heapSort(int *arr, int N) 
{
    int t; /* the temporary value */
    unsigned int n = N, parent = N/2, index, child; /* heap indexes */
    /* loop until array is sorted */
    while (1) { 
        if (parent > 0) { 
            /* first stage - Sorting the heap */
            t = arr[--parent];  /* save old value to t */
        } else {
            /* second stage - Extracting elements in-place */
            n--;                /* make the heap smaller */
            if (n == 0) {
                return; /* When the heap is empty, we are done */
            }
            t = arr[n];         /* save lost heap entry to temporary */
            arr[n] = arr[0];    /* save root entry beyond heap */
        }
        /* insert operation - pushing t down the heap to replace the parent */
        index = parent; /* start at the parent index */
        child = index * 2 + 1; /* get its left child index */
        while (child < n) {
            /* choose the largest child */
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++; /* right child exists and is bigger */
            }
            /* is the largest child larger than the entry? */
            if (arr[child] > t) {
                arr[index] = arr[child]; /* overwrite entry with child */
                index = child; /* move index to the child */
                child = index * 2 + 1; /* get the left child and go around again */
            } else {
                break; /* t's place is found */
            }
        }
        /* store the temporary value at its new location */
        arr[index] = t; 
    }
}
   
int main()
{
    int i;
 
    heapSort(arr, 10);
    for (i=0; i<10; i++) printf(" %d ", arr[i]);
    printf("\n");
    return 0;
}
