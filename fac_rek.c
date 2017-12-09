#include <stdio.h>

unsigned long faculty(int n)
{
  if ( n > 1 )
    return n * faculty( n - 1 );
  return 1;
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
    