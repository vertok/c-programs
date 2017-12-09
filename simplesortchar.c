#include <stdio.h>
#include <string.h>
#define N 10
 
int main(){
    char *data[N]={"Max", "Moritz", "Bolte", "Hans", "Huckebein", "Helene", "Antonius", "Boeck", "Maecke", "Lempel"};
    //int size_array=sizeof(data)/sizeof(char *); 
    int n,m,code;
for(n=1;n<N;n++)
for(m=0;m<N-n;m++)
{
    code=strcmp(data[m+1],data[m]);//Vergleich von Elementen
            if(code<0)		   //da mit logischen Vergleich klappt es nicht
            {
                char *tmp=data[m]; 
                data[m]=data[m+1];
                data[m+1]=tmp;               
            }
            }


for(int j=0;j<N;j++)
    printf("%s ",data[j]);
printf("\n");
return 0;

}
