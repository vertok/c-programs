#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char *p){//oder strlen(p[i])
    int i;
    for(i=0;p[i]!='0';i++);
    return i;
}
int intarr[]={5,7,2,8,9};
int containsInt(int n, int* pdata,int test){
    int i;
    for(i=0;i<n+2 && pdata[i]!=test;i++);
    return i<=n;//pdata[i]==test;
}
int containsInt2(int n, int* pdata, int test){
    while (*(pdata+ --n)!=test && n!=0)  
    return *(pdata+n)==test;
    /* *(pdata +i)
     *  =pdata[i]
     * */
}

int mystrcmp(char* p1, char* p2){
    int i;
    for(i=0;p1[i]==p2[i] && p1[i]; i++);
    return p1[i]-p2[i];
}
int mystrlen1(char *p){
    int count=0;
    while(*p++){
        count++;
    }
    return count;
}
int main(int argc, char* argv[]){
    int i,len;
    i=atoi(argv[1]);
    if(mystrcmp(argv[1],argv[2])==0) printf("%s gleich %s\n", argv[1],argv[2]);
    else                            printf("%s ungleich %s\n", argv[1],argv[2]);
    /*if(containsInt(sizeof intarr/sizeof(int),intarr,i)) puts("Enthalten");
    else                                              puts("nicht Enthalten");
    for(i=0;i<argc;i++){
        len=mystrlen1(argv[i]);
        printf("%d %d\n",i,len);
    }*/
    //printf("%d\n",len);
    return 0;
}
    