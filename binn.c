#include <stdio.h>
int a[]={1,2,3,4,5,8,9,9,15};
int bsearch(int a[], int n, int val){
    if(n==0) return 0;
    else if(a[n/2]==val) return 1;
    else if(a[n/2]<val) return bsearch(a+n/2-1,n-n/2-1,val);
    else return bsearch(a,n/2-1,val);
    }
int main(){
    int v=0;
    int size= sizeof a/ sizeof(int);
    printf("i=");
    scanf("%d",&v);
    int b=bsearch(a,size,v);printf("%d\n",b);
    if(bsearch(a,size,v)==1) printf("+\n");
    else printf("-\n");
    return 0;
}