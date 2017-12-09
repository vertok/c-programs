#include <stdio.h>

int A[]={1,2,3,4,6,11,18,234}; //falls die Länge verändert wird, sollten Sie auch an die Werte
//int B[]={2,3,4,5};//von sizeI und sizeJ anpassen. 
int B[]={3,7,8,9};
int C[]={0};
int sizeI=8,sizeJ=4;//Mächtigkeit von A[] und B[]

int main(){
int i=0,j=0,k=0;

while((i!=sizeI+1)&&(j!=sizeJ+1)&&(k<(sizeI+sizeJ))){
    if (A[i]<=B[j])
        { 
           C[k]=A[i];
           i++;
        }
        else
        {
           C[k]=B[j];
           j++;
        }
    k++;
}
    k--;
    if (i == (sizeI+1) )//nun  Wenn aus a schon alle Werte eingefügt sind,
                        //muss man nur noch die Werte
                //  aus b auffüllen; etc
                for (; k < (sizeI+sizeJ); k++) {
			  C[k] = B[j];
			  j++;}
    else
                for (; k < (sizeI+sizeJ); k++) {
			  C[k] = A[i];
			  i++;}
for(i=0;i<(sizeI+sizeJ);i++) 
            printf("%d ",C[i]);
printf("\n");

return 0;
}