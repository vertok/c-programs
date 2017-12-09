#include <stdio.h>
#define N 10

int arr[N] = {5,2,6,0,11,7,6,7,4,2};

void insertSort(int* arr, int size) 
{
    int i, j, tmp;
 for(i=1;i<size;i++){
      tmp=arr[i];
      j=i-1;
      while((tmp<arr[j])&&(j>=0)){
         arr[j+1]=arr[j];
         j=j-1;
      }
      arr[j+1]=tmp;
   }
}

int main()
{
	int i;
	printf("\nUnsorted array is:  ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
        insertSort(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\nSorted array is:    ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
        printf("\n");
   return 0;
}
