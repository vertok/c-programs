#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
int main()
{
  
	printf("Diese Anwendung stellt graphisch eine periodische lineare Funktion dar\n");
        int a,l,a1;char e;
        printf("Geben Sie bitte a(Höhe)    ein:\n");
        scanf("%d",&a);
        printf("Geben Sie bitte l(Periode) ein:\n");
        scanf("%d",&l);
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);//malt nur in resolution 640*480px
        
               
        
                        
                        line(l-20,2*a,12*l,2*a);//unsere x-Achsee
                        line(12*l,2*a,12*l-0.25*l,1.75*a);//malt die Pfeile auf x-Achsee
                        line(12*l,2*a,12*l-0.25*l,2.25*a);
                        outtextxy(12*l, 2*a+5, " x");// nennt unsere x-Achse als "x"
                        line(1.5*l,0,1.5*l,4*a);//unsere y-Achsee
                        line(1.5*l,0,1.6*l,0.5*a);//malt die Pfeile auf y-Achsee
                        line(1.5*l,0,1.4*l,0.5*a);
                        outtextxy(1.2*l, 5, " y");
	     		for(int k=0;k<=9;k++){ //malt unseren Graph
			if(k%2==0){
                            setcolor(BLUE);
                            line(l+k*l,2*a+a,l+(k+1)*l,a);  
                            }
			else{ 
                            setcolor(RED);    
                            line(l+k*l,a,l+(k+1)*l,2*a+a);
                            e=k+'0';
                            outtextxy(l*k+0.3*l, 2*a+5, &e);//zeigt Periode
                            };};


	//delay(50000);
        getch();
        closegraph();
	return 0;


}
