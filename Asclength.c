#include <stdio.h>
//auf der WEbSeite arbeitet nicht. habe versucht was zu ändern, aber sowieso klappt es nicht. keine ahnung, tut mir leid
int a[]={1,2,5,8,2,5,7,9,12,13,10,6};
//int a[]={1,2,3,5,6,2,3,4,5,1,2,3};

int findAsclength(int *a, int n){
	int i,k=1,tmp=0;
	for(i=0;i<n;i++){
       			     if(a[i]<a[i+1]) 
					   k++;//zählt die Laenge von der Sequenze von elementen
			     else {if(k>tmp) {tmp=k;k=1;} //fängt das neu zu zählen
				   else k=1;
			 	  } 
					   
			 }
	return tmp;

}

int main(){
	   printf("Die laengste Teil von Array, in der die Elemente stehen in der Ordnung unter der Groesse, ist: %d\n",findAsclength(a,12));
	   return 0;
}
