#include <stdio.h>

int a[]={1,2,5,8,2,5,7,9,12,13,10,6};

void find(int *a, int n){
        int i,count=0;
	int l[]={0};
	for(i=0; i<12; i++){
				if(a[i]==n) {a[count]=i+1;
					    count++;
					     }
				}
        if(count==0) printf("\nIn unserem Array gibt's keine Zahl %d!\n",n);
	else if(count==1) printf("\nIhre Zahl steht in unserem Array auf der Stelle: ");
	else printf("\nIhre Zahl steht in unserem Array auf den Stellen: ");
	for(i=0; i<count;i++) printf("%d ",a[i]);
}
int main(){
int z;
printf("Was für ein Elemen wollten Sie in Array finden?\n");
scanf("%d",&z);
find(a,z);
printf("\n");
return 0;
}


