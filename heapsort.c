#include <stdio.h>
#define N 10 

int arr[N] = {5,2,6,0,11,7,6,7,4,2}; 
 
void siftDown( int *arr, int start, int end) //vergleich Vater-element mit Kind-element
{
    int vater = start;
 
    while ( 2*vater+1 < end ) {
        int child = 2*vater + 1;
        if ((child+1<end)&&(arr[child]<arr[child+1])){
                                                  child += 1;
                                                 }
        if (arr[vater]<arr[child]) { 
            int tmp=arr[child];
                arr[child]=arr[vater];
                arr[vater]=tmp;
                vater = child;
        }
        else
            return;
    }
}

void heapSort( int *arr, int count)
{
    int start, end;
 
    for (start = (count-2)/2; start >=0; start--) {
       siftDown( arr, start, count);
    }
 
    for (end=count-1; end > 0; end--) {
            int tmp=arr[end];
                arr[end]=arr[0];
                arr[0]=tmp;
       siftDown(arr, 0, end);
    }
}
   
int main()
{
    int i;
    printf("\nUnsorted array is:  ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
    heapSort(arr, N);
    printf("\nSorted array is:    ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
