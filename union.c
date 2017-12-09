#include <stdio.h>
#include <stdlib.h>
struct BYTE {

unsigned a: 1;

unsigned b: 1;

unsigned c: 1;

unsigned d: 1;

unsigned e: 1;

unsigned f: 1;

unsigned g: 1;

unsigned h: 1;

};

union SYMB {

unsigned char ch;

struct BYTE bit;

}symbol;

int main(){

do {
symbol a;
a.ch=getche(); /* Функция getche читаетсимвол */
printf(":"); /* и отображает его на экране */

if (simbol.bit.h) printf("1");else printf("0");
if (simbol.bit.g) printf("1"); else printf("0");
if (simbol.bit.f) printf("1"); else printf("0");
if (simbol.bit.e) printf("1"); else printf("0");
if (simbol.bit.d) printf("1"); else printf("0");
if (simbol.bit.c) printf("1"); else printf("0");
if (simbol.bit.b) printf("1"); else printf("0");
if (simbol.bit.a) printf("1"); else printf("0");

printf("\n");
}
while (symbol.ch!='$');
return 0;
}