#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ttre
{
  char* pData;
  struct ttre *li;
  struct ttre *re;
}tTre;

tTre * pTree;
tTre TreeInit={NULL,NULL,NULL};

int cmpData(void* p1,void*p2)
{
  return strcmp((const char*)p1, (const char*)p2);
}

void addToTree(tTre *pTree, void* pItem, 
               int (*fcmp)(void*,void*))
{
   if(pTree->pData==NULL)pTree->pData=pItem;
   else
   {
     if (fcmp(pTree->pData, pItem)>0)
     {//links
        if (pTree->li==NULL)
        {pTree->li=malloc(sizeof(tTre));*(pTree->li)=TreeInit;}
        addToTree(pTree->li, pItem, fcmp);
     }
     else
     {//rechts
        if (pTree->re==NULL)
        {pTree->re=malloc(sizeof(tTre));*(pTree->re)=TreeInit;}
        addToTree(pTree->re, pItem, fcmp);
     }
   }
}
void dispTree(tTre*pTree, void (*f) (void*))
{
  if (pTree)
  {
    dispTree(pTree->li,f);
    f(pTree->pData);
    dispTree(pTree->re,f);
  }
}
void disp(void* pData)
{
  puts((char*)pData);
}
char* vData[]={"Max","Moritz","Hans","Peter","Albert","Johann",
             "James", "Franz", "Thomas","Jens"};
int main()
{
  int i;
  pTree=malloc(sizeof (tTre));
  *pTree=TreeInit;
  for (i=0; vData[i]; i++)
    addToTree(pTree,vData[i],cmpData);
  dispTree(pTree,disp);
  return 0;
}






