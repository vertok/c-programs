#include <stdio.h>
#include <stdlib.h> 

char vBuf[128];

char* crtBitStr(int x)
{
   // printf("%d\n",sizeof(x));
   
   // dualzahl erstellen
   int rest,j,temp;
   temp=x;
   int i=(sizeof(int)*8+1);
   //länge der Dualzahl von 32 oder 64bit system abhnängig
   static char dual[sizeof(int)*8+1];
   
   while (i!=0)
    {
      //modulooperation
      rest=temp%2;
      temp=temp/2;
      i--;
      //zählt zurück bis 0
      dual[i]= rest + '0';
      //gibt dualzahl an hauptprogramm zurück
    } 
    //ausgabe formatieren
    //0000 0000|0000 0000|0000 0000|
    
    return dual;
}


/*har* ctrHexStr(int x)
{
 
 
  
}
*/


int main()
{
  int dez=0;
  char *dualvar;//[sizeof(int)*8+1];
  printf("Eingabe einer int-Zahl: "); fgets(vBuf,128,stdin);
  dez=atoi(vBuf);
  dualvar=crtBitStr(dez);
  printf("Bin: %s\n",dualvar);  
  printf("Hex: 0x%x\n",dez);
  
  printf("\n");
  
  return 0;
}
