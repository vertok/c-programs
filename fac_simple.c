#include <stdio.h>

unsigned long faculty(int n)
{
    unsigned long f=1;
    for(;n>1;n--)
        f*=n;
    return f;
}

int main()
{
    int n;
    printf("Geben Sie die Zahl: ");
    scanf("%d", &n);
    if(n<0)
        printf("Falsche Eingabe!\n");
    else
        printf("Fakultaet ist gleich: %lu\n", faculty(n));
    return 0;
}