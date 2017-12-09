#include <stdio.h>
#define N 10

int arr[N] = {5,2,6,0,11,7,6,7,4,2}; 

void simpleSort(int *arr){
int i,j,tmp;
for(i=0;i<N-1;i++)
for(j=i;j<N;j++)
        if(arr[i]>arr[j]){
                         tmp=arr[i];      //arr[i]^=arr[j];   so haben wir gelernt bei der Vorlesung, 
                         arr[i]=arr[j];   //arr[j]^=arr[i];   aber so geht nicht in unserem Kompilator
                         arr[j]=tmp;      //arr[i]^=arr[j];   *bit for bit addieren*
                          }
                          

    
}

int main()
{
    int i;
    printf("\nUnsorted array is:  ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);
    simpleSort(arr);
    printf("\nSorted array is:    ");
	for(i = 0; i < N; i++)
		printf("%d ", arr[i]);   
    printf("\n");
    return 0;

}
