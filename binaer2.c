#include <stdio.h>
#define N 9


int binsearch (int arr[], int links, int rechts, int wert)
{
    if (links > rechts)
    {
        printf("Fake...");
        return -1;
    }
    int mitte = (rechts+links)/2;
    if (arr[mitte] == wert) 
    {
        printf("1 ");
        return mitte;
    }
    if (wert < arr[mitte]) 
    {
        printf("3 ");
        return binsearch(arr, links, mitte - 1, wert);
    } else 
    {
        printf("4 ");
        return binsearch(arr, mitte + 1, rechts, wert);
    }
}
int main()
{
    int arr[N]={1,2,3,4,5,8,9,9,15};
    int i;
    for(i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\ni=");
    scanf("%d",&i);
    int size=sizeof arr/sizeof(int);
    if(binsearch(arr,0,size-1,i)!=-1)
        printf("Bingo!!!\n");    
    return 0;
}
