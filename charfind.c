#include <stdio.h>
#include <string.h>
#define N 10
 
int main(){
    char *data[N]={"Max", "Moritz", "Bolte", "Hans", "Huckebein", "Helene", "Antonius", "Boeck", "Maecke", "Lempel"};
    char words[N];
    //int size_array=sizeof(data)/sizeof(char *); 
    int n=0,m,code;
    printf("Geben Sie ein Wort: \n");
    scanf("%s",words);
    for(m=0;m<N;m++)
        {
            code=strcmp(data[m],words);//Vergleich von Elementen
            if(code==0) n=1;           //falls einmal tritt, dann macht es n=1
               
        }
                  if(n==1) printf("das Wort \"%s\" wurde gefunden\n",words);
                  else printf("not found\n");
    return 0;
}