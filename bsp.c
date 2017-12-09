#include <stdio.h>

int main(){

int i=99, *pi=&i;
//& heisst Adress operator
printf("i:%d &i: %p\n",i,&i);
//*pi dereferensieren
printf("pi: %lx &pi: %p, *pi=%d\n",pi,&pi,*pi);
printf("pi: %lx &pi: %p, *pi=%d\n",pi,&pi,pi[0]);
return 0;

}
