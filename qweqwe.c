

#include<graphics.h>
#include<stdio.h>

 
int main()
{
   int gd = DETECT, gm, drawing_color;
   char a[100];
 
   initgraph(&gd,&gm,"C:\\TC\\BGI");
      setcolor(RED);
   drawing_color = getcolor();
 line(100,100,50,50);
   sprintf(a,"Current drawing color = %d", drawing_color);
   outtextxy( 10, 10, a );
 
   getch();
   closegraph();
   return 0;
}
