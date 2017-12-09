#include <stdio.h>
#include <stdlib.h>
//#define NULL (void *)0

int main(void) {
   int x=5;
   int *y;

   printf("Adresse x=%p, Wert x=%d\n", &x, x);

   /*  Führt bei manchen Systemen zum Programmabsturz,
    *  ggf. auskommentieren. */
   printf("Adresse *y=%p, Wert *y=%d(unsinn)\n", &y, *y);
   printf("\ny=&x;\n\n");

   /* y hat jetzt die Adresse von x. */
   y =& x;
   printf("Adresse  x=%p, Wert x=%d\n", &x, x);
   printf("Adresse *y=%p, Wert *y=%d\n", &y, *y);
   printf("\nAdresse, auf die y zeigt, ist %p\n", y);
   printf("und das ist die Adresse von x = %p\n", &x);

   printf("\nACHTUNG!!!\n\n");
   *y=10;
   printf("*y=10\n\n");
   printf("Adresse  x=%p, Wert  x=%d\n", &x, x);
   printf("Adresse *y=%p, Wert *y=%d\n", &y, *y);
   printf("\nAdresse, auf die y zeigt, ist %p\n", y);
   printf("weiterhin die Adresse von x (%p)\n", &x);
   
   int *c=NULL;
   if(c==NULL){ printf("Der Zeiger besitzt keine gültige Adresse!\n");
   return EXIT_FAILURE;
}
   else {*c=10;}

   printf("Der Wert &c%p c%p von *c ist %d\n", &c,c,*c);
   
   
   
   return EXIT_SUCCESS;
}

