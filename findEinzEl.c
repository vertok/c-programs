#include <stdio.h>

int a[]={1,2,5,8,2,5,7,9,12,13,10,6};

int find(int *a, int n){
        int k;
	for(int i=0; i<12; i++){
				if(a[i]==n) k=i+1;
				}
	return k; 
}
int main(){
int z;
printf("Was für ein Elemen wollten Sie in Array finden?\n");
scanf("%d",&z);
printf("Ihre Zahl steht in unserem Array auf der Stelle %d.\n",find(a,z));
return 0;
}


