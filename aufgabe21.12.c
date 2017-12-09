#include <stdio.h>
    union xx {
      long l;
      struct ab {
        short a;  /* low word  */
        short b;  /* high word */
      } ab;
    } c;
int main(){ /* 00020001 */
      c.ab.a = 1; c.ab.b = 2; printf("%08lx\n", c.l );
return 0;    
}
