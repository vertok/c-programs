#include <stdio.h>
#define N 9

/**
 * Binaer Suche
 * als die Forauszetzung nutzt man ein sortiertes Array
 */

int binsearch (int arr[], int links, int rechts, int wert)
{
    int pivot = (rechts+links)/2;
    /*Element wurde nicht gefunden */
    if (links > rechts)
    {
        printf("->Fail...\n"); 
        return 0;
    }
    /* Element wurde getroffen */
    if (arr[pivot] == wert) 
    {
        printf("->Bingo!!!\n"); 
        return 0;
    }
    /* Suchverhalten geht nach links */    
    if (wert < arr[pivot]) 
    {
        printf("->links"); 
        return binsearch(arr, links, pivot - 1, wert);
    } 
    /* Suchverhalten geht nach rechts */
    else 
    {
        printf("->rechts");
        return binsearch(arr, pivot + 1, rechts, wert);
    }
}
int main()
{
    int arr[N]={0,2,3,6,7,8,9,12,15};
    int i;
    for(i=0;i<N;i++)
        printf("%d ",arr[i]); /* Ausgabe unseres Array */
    printf("\ni=");
    scanf("%d",&i);
    int size=sizeof arr/sizeof(int); /* eigentlich ist gleich N */
    binsearch(arr,0,size-1,i);
    return 0;
}
