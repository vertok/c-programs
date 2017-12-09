#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* upperstr(char *data){
int i=0;
    while(*(data)!='\n')
    {
        //data[i]=toupper(data[i]);
       // if(data[i]>='a' && data[i]<='z') data[i]&=~(1<<5);//1101 1111 0010 0000
        *data=toupper(*data);
        data++;
        //i++;
    }
    return data;


}
char vbuf[128];
int main(){
printf("Eingabe: ");
fgets(vbuf,128,stdin);
upperstr(vbuf);
puts(vbuf);
return 0;
}