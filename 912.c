#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char vbuf[128];
char buf[128];
typedef struct{
    char name[28+1];
    int matrNr:16;
    int belNote:3;
    float klNote;
    struct{
        int jj,stGang,stgr;
    }stGr;
}tStud;
void getStud(tStud pStud){
printf("Name von Student:\n");
fgets(buf,128,stdin);
buf[strlen(buf)-1]=0;
strcpy((*pStud).name,buf);
printf("Matrikel Nr.:\n");
fgets(buf,128,stdin);
(*pStud).matrNr=atoi(buf);

}
void putStud(tStud s){
        printf("%-28s %d\n",s.name, s.matrNr);
}

tSud s,ps=NULL;
int anz=0;

char weiter='y';
int main(){
    if(ps==NULL){
        ps=malloc(sizeof(tStud));
        if(ps==NULL) puts("malloc hat nicht geklappt\n");
    else {tStud psx=realloc(ps, (anz+1)*sizeof(tStud));
        if(psx) ps=psx;
        else puts("nicht geklappt\n")exit(-1);}
    }
   // tStud* ps=malloc(sizeof(tSutd));
while(weiter=='y'){
   s=getStud;    
   *ps=s;anz++;
   for(i=0;i<anz;i++) putStud(ps+i);
   printf("next y/n: ");
   fgets(vbuf,128,stdin);weiter=vbuf[0];
}
free(ps);
return 0;
}