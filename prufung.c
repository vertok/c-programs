#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
 char vBuf[128];
 int checked;
 
 printf("sizeof(argv[1])=%d\n",sizeof(argv[1]));
 
 while(1)
 	{
 	 fgets(vBuf,128,stdin);
 	 if(vBuf[0]==argv[1][0])
 	 	{
 	 	 printf("Erfolg\n");
 	 	 checked=1;
 	 	 if(checked==1)
 	 	 	{
 	 	 	 fgets(vBuf,128,stdin);
 	 	 	 if(vBuf[0]==argv[1][1])
 	 	 		{
 	 	 	 	 printf("Erfolg\n");
 	 	 	 	 checked=1;
 	 	 	 	 fgets(vBuf,128,stdin);
 	 	 	 	 if(vBuf[0]==argv[1][2])
 	 	 	 	 	{
	 	 	 	 	 printf("Erfolg\n");
	 	 	 	 	 checked=1; 	
	 	 	 	 	 fgets(vBuf,128,stdin);
 	 	 	 	 	 if(vBuf[0]==argv[1][3])
 	 	 	 	 		{
	 	 	 	 	 	 printf("Erfolg\n");
	 	 	 	 		 checked=1;
	 	 	 	 		 printf("!!!ENTSCHLUESSELT!!!");
	 	 	 	 		 continue; 	 	 	 
 	 	 	 	 		}
 	 	 	 	 	 else
 	 	 	 	 		{
 	 	 	 	 		 printf("Misserfolg4\n");
 	 	 	 	 	 	 checked=0;
	 	 	 	 	 	 continue; 	 	 	 	 	 
 	 	 	 	 		}	 	 	 	 	  	 	 	 	 
 	 	 	 	 	}
 	 	 	 	 else
 	 	 	 	 	{
 	 	 	 	 	 printf("Misserfolg3\n");
 	 	 	 	 	 checked=0;
	 	 	 	 	 continue; 	 	 	 	 	 
 	 	 	 	 	}
 	 	 		}
 	 	 	 else
 	 	 	 	{
 	 	 	 	 printf("Misserfolg2\n");
 	 	 	 	 checked=0;
 	 	 	 	 continue;
 	 	 	 	}
 	 	 	}
 	 	}
 	 else
 	 	{
 	 	 printf("Misserfolg1\n");
 	 	 checked=0;
 	 	 continue;
 	 	}
 	}
 return 0;
}