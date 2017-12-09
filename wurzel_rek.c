#include  <stdio.h>
#define N 14   // Die Anzahl der Rekursionen

double  wurzel(int n, double x)
{
    if (n==0) 
        return 1;
    else 
        return  0.5*( wurzel(n-1, x)+x/wurzel(n-1, x));
}
int  main(void)
{
    double x;
    printf ("Zahl  eingeben: ");
    scanf ("%lf", &x);
    if(x<0)
        printf("Falsche Eingabe!");
    else
        printf ("Die  Wurzel  von %f ist  etwa  %1.4f\n",
                x, wurzel(N,x));
    return 0;
}