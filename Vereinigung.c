#include <stdio.h>

enum book{ a,b,c,d,e,f,g,h }; 

union result {
    long l;
    enum book books;
    struct numbers {
        int a:4;  /* low word  */
        int b:4;  
	int c:4;
        int d:4;   
        int e:4;   
	int f:4;
        int g:4;
        int h:4;  /* high word */
        } numbers;
    } result;
/*struct pwk{
        int j;
        union result p;
            }pwk;*/
int main(){/* 75439321 */
      result.numbers.a = 1; result.numbers.b = 2; result.numbers.c = 3; result.numbers.d = 9; //wegen der Schöneheit sollten die Zähle <10 sein,
      result.numbers.e = 3; result.numbers.f = 4; result.numbers.g = 5; result.numbers.h = 7; //da am sonst sie sich z.b. als Buchstaben umsetzen( da später Hex genutzt wird
        printf("%08lx\n", result.l ); //unsere 8 Zahlen werden hier unter "union" als eine Zahl vereinigt
      return 0;
    }
//die Hauptaufgabe ist noch nicht klar(bzw. noh nicht fertig), aber ich habe solche lüstige Sache gebastelt
//ich habe mit der Kode gespielt und folgendes gekrigt.