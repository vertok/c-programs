#include <stdio.h>

int such( int arr[], int suchElem)
{
int hi = 6;
int lo = 0;
while(lo < hi)
{
  int mid = (lo+hi);
  int midval = arr[mid];
  if (midval < suchElem)
    lo = mid+1;
  else 
      if (midval > suchElem)
    hi=mid;
  else
    return midval;
}
}

int main()
{

int arr[6]={3,2,6,1,5,4};
int suchElem=2;

printf("%d ", such(arr,2));
return 0;
}