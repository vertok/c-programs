#include <stdio.h>
#define N 10

int arr[] = {5,2,6,0,11,7,6,7,4,2};
//int arr[]={3,7,5,1,1,9,1,2,4,6};
int partition( int *arr, int l, int r) {
   int pivot;//unseres Trennelement
   int i, j, t;
   i = l; j = r+1;//l- left, r- right
   
        if(r-l > 3){ //**********"Median of three"*********** 
                     //die Ergaenzung beschleunigt die LZ um >5%
                     //*laut http://www.linux-related.de/index.html?/coding/sort/sort_quick.htm
		pivot=(l+r)/2;
		if(arr[l]>arr[pivot])
		  { t=arr[l]; arr[l]=arr[pivot]; arr[pivot]=t; }
  		if(arr[l]>arr[r])
		  { t=arr[l]; arr[l]=arr[r]; arr[r]=t; }
  		else if(arr[r]>arr[pivot])
		  { t=arr[r]; arr[r]=arr[pivot]; arr[pivot]=t; }
	}               //Ende der Ergaenzung
   
   pivot = arr[l];

   while(1)
   {
   	do {i++;}
            while( arr[i] <= pivot && i <= r );
   	do {j--;}
            while( arr[j] > pivot );
   	if( i >= j ) break;
   	t = arr[i]; arr[i] = arr[j]; arr[j] = t;
   }      
   t = arr[l]; arr[l] = arr[j]; arr[j] = t;
   return j;
}
void quickSort( int *arr, int l, int r)
{
   int j;

   if( l < r ) 
   {
       //Divide et impera! *Motto des Algorithmus, was auf Deutsch "Teile und herrsche" laut*
       j = partition( arr, l, r);
       quickSort( arr, l, j-1);
       quickSort( arr, j+1, r);
   }
	
}

int main() 
{
	int i;
	printf("\nUnsorted array is:  ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
        quickSort( arr, 0, N-1);
        printf("\nSorted array is:    ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
        printf("\n");
return 0;

}








