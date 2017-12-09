#include <stdio.h>
#define N 10
int arr[N] = {5,2,6,0,11,7,6,7,4,2}; 

void bubbleSort(int *arr, int size)
{
    int tmp, i, j;
 
    for(i = 0; i < size - 1; i++) 
    {            
        for(j = 0; j < size - 1; j++) 
        {     
            if (arr[j + 1] < arr[j]) 
            {
                tmp = arr[j + 1]; 
                arr[j + 1] = arr[j]; 
                arr[j] = tmp;
            }
        }
    }
}

int main() {
   int i = 0;
   bubbleSort(arr, N);
   
   for (i = 0; i < N; ++i) {
      printf("%d ", arr[i]);
   }
   printf("\n");
   return 0;
}
