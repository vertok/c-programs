#include <stdio.h>
#include <stdlib.h>

int binsearch (int feld[], int links, int rechts, int wert) {
    if (links > rechts) {
        return -1;
    }
    int mitte = (rechts+links)/2;
    if (feld[mitte] == wert) {
        return mitte;
    }
    if (wert < feld[mitte]) {
        return binsearch(feld, links, mitte - 1, wert);
    } else {
        return binsearch(feld, mitte + 1, rechts, wert);
    }
}

int main()
{
int a[]={1,2,3,4,5,6,7,8,9};
int i;
i=binsearch(a,0,8,7);
printf("%d ",i);
return 0;
}