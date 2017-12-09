#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double sinus(double x);

char vbuf[128];

int main(){
double x,y;
fgets(vbuf,128,stdin);
x=atoi(vbuf);


double sinus(double x){

int i=2,vz=-1;
double erg=x, summand=x;
while(summand>0.000005){

    summand=summand*x*x/(i*(i+1));
    i+=2;
    erg+=summand*vz;
    vz*=-1;
    }
return erg;
}
printf("sin= %lf\n",sinus(x));
return 0;
}