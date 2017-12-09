#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	line(10,10,250,250);//x achse
	line(getmaxx()/3,0,getmaxx()/3,getmaxy()/3);
        line(2,getmaxy()/3,getmaxx(),getmaxy()/3);
	setcolor(BLUE);
	circle(getmaxx()/2,getmaxy()/2,150);

	setcolor(GREEN);
	circle(getmaxx()/2,getmaxy()/2,75);

	setcolor(RED);
	circle(getmaxx()/2,getmaxy()/2,25);


	delay(50000);
	closegraph();
	return 0;


}
