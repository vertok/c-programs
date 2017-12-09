#include <stdio.h>
#define N 10

int arr[] = {5,2,6,0,11,7,6,7,4,2}; 
//int arr[] = {0,2,2,4,5,6,6,7,7,11}; 

void bubbleSort(int *arr, int size)
{
    int tmp, j;
    int tausch=1;//da in C fehlt boolean typ, nutzen wir hier int(1=true,0=false)
    while(tausch){
    
        tausch=0;
        for(j = 0; j < size - 1; j++) 
         
        {     
            if (arr[j + 1] < arr[j]) 
            {
                tmp = arr[j + 1]; 
                arr[j + 1] = arr[j]; 
                arr[j] = tmp;
                tausch=1;
           
           }
        
       } 
       size--;//die Länge von Array reduziert sich, da ein Element schon seine richtige stelle hat
    }
}

int main() 
{
	int i;
	printf("\nUnsorted array is:  ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
        bubbleSort(arr,N);
        printf("\nSorted array is:    ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
        printf("\n");
return 0;
}
