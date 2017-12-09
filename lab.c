#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct labb{
    char value[9+1];
    struct labb *next;    
    }lab;

void shift(lab *i, lab **last){
        if(!*last) *last=i;
        else (*last)->next=i;
        *last=i;
}
int main(){
lab *p;  
int i,size;


lab labirint[10]={"IN A"};
                //{"A IN B C"},
                //{"B A"}};
size=sizeof labirint/sizeof(lab);
printf("%d\n",size);
for(i=0;i<2;i++){
    lab* p = (lab*) malloc(sizeof(lab));
    char s=labirint[i].value;
    p->value=s;
    printf("%-3s\n",p[i].value);
}
//int main(){
    //
  
    
 //    printf("%d",size);
    return 0;
}
    