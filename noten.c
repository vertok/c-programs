#include <stdio.h>
#include <stdlib.h>

char vBuf[128];
int Noten[]={5,2,3,4,5,5,2,3,4,5};

double CalcMean(int *Noten, int n)
{
double Akku=0.0;
int  Count=0;
printf("%d\n",sizeof Noten/ sizeof(int));
while(Count<n)
{
Akku=Akku+ *Noten++;
//Noten[Count]=99;
Count++;
}
if(Count>0)
Akku=Akku/Count;
return Akku;

}

int main(){

double mean=0.0;

mean=CalcMean(Noten,10);//Uebergeben wird die Adresse des erstens Wertes von Noten
printf("Durchschnitt: %lf\n", mean);
for(int i=0;i<sizeof Noten /sizeof(int);i++) printf("%d",Noten[i]);
return 0;
} 
