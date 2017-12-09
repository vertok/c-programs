#include  <stdio.h>

double sqroot(double square)
{
    double root=square/3;
    int i;
    /**
     * hier lassen wir die for-Schleife 32 mal durchlaufen.
     * Es könnte mehr oder weniger sein.
     * Es hängt nur von der Genauigkeit an
     */
    for (i=0; i<32; i++) 
        root = (root + square / root) / 2;
    return root;
}
int  main()
{
    double x;
    printf ("Zahl  eingeben: ");
    scanf ("%lf", &x);
    if(x<0)
        printf("Falsche Eingabe!");
    else
        printf("Die  Wurzel  von %f ist  etwa  %1.4f\n",
               x, sqroot(x));
    return 0;
}