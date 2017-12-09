#include <graphics.h>
#include <stdio.h>
int main(int argc,char ∗argv[] ){
char zeich ;
int iZahl;
double dZahl;
const char ∗string ;

initgraph( 400, 250 );
cleardevice( WHITE );


zeich = getcharacter( ”Gib ein Zeichen ein!” );
iZahl = getint( ”Gib eine ganze Zahl ein!” );
dZahl = getdouble( ”Gib eine Zahl ein!” );
string = getstring( ”Gib einen beliebigen Text ein!” );
outtextxy( 100,  50, 400, 250, ”Das Zeichen ist: %c”, zeich );
outtextxy( 100, 100, 400, 250, ”Die ganze Zahl ist: %d”, iZah
l  );
outtextxy( 100, 150, 400, 250, ”Die Gleitpunktzahl ist: %g”
, dZahl );
outtextxy( 100, 200, 400, 250, ”Der Text ist: %s”, string  );
getch();
closegraph();
return(0);
}
