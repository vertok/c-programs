#include <stdio.h>
#define N 10

//int a[] = {5,2,6,0,11,7,6,7,4,2};
int a[]={3,7,5,1,1,9,1,2,4,6};

  void qsort_median(int a[], int l, int r){
	if(r>l){
	  int i=l-1, j=r, tmp;
        if(r-l > 3){ //Median of three
		int m=(l+r)/2;
		if(a[l]>a[m])
		  { tmp=a[l]; a[l]=a[m]; a[m]=tmp; }
  		if(a[l]>a[r])
		  { tmp=a[l]; a[l]=a[r]; a[r]=tmp; }
  		else if(a[r]>a[m])
		  { tmp=a[r]; a[r]=a[m]; a[m]=tmp; }
	}

	  for(;;){
		while(a[++i]<a[r]);
		while(a[--j]>a[r] && j>i);
		if(i>=j) break;
		tmp=a[i]; a[i]=a[j]; a[j]=tmp;
	  }
	  tmp=a[i]; a[i]=a[r]; a[r]=tmp;

	  qsort_median(a, l, i-1);
	  qsort_median(a, i+1, r);
	}
  }

int main() 
{
	int i;
	printf("\nUnsorted array is:  ");
	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
        qsort_median( a, 0, N-1);
        printf("\nSorted array is:    ");
	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
        printf("\n");
return 0;

}








