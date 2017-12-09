#include <stdio.h>
long fakult(int x)
{
long f=1;
for(;x>1;x--){
f*=x;
printf("x: %d\n", x);}
return f;
}




long fak(int x){
long f;
if(x>1) f=x*fak(x-1);
else f=1;
return f;
}
int main(){
int x;
printf("Geben Sie x: ");
scanf("%d",&x);
printf("Fakult von x: %ld\n", fakult(x));
return 0;
}
