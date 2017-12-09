#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sinx(double x)
{
    double n = x;
    double sum = 0.0;
    int i = 1;
 
    do
    {
        sum += n;
        n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    }
    while ((n > 0.0 ? n : -n) > 1E-12);
 
    return sum;
}

int main(){
    double x;
    int s;
    printf("Geben Sie bitte Ihr Winkel in Radian( pi=3.1415)\n");
    scanf("%lf",&x);
    s=10000*sinx(x);
        int z=s/10000; // hier machen wir 4 Stellieger Ende von Zahl
        int n=s%10000;
        printf("sin(x)= %d.%04d\n",z,n);
        printf("std sinx= %lf\n",sin(x));

    //printf("%lf\n",sinx(x));
    return 0;

}
       
    