#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
  int elem;
  struct tree *li;
  struct tree *re;
}tree;

tree * binTree;
tree * searchTree;
tree TreeInit={0,0,0};

int cmpElem(int el1,int el2)  /* compare func. */
{
  if(el1==el2) return 0;
  else if(el1>el2) return 1;
  else return -1;
}

void treeIns(tree *binTree, int key, 
               int (*fcmp)(const int,const int))  /* pointer zu cmpElem */
{
   if(binTree->elem==0)binTree->elem=key;
   else
   {
     if (fcmp(binTree->elem, key)>0)
     {//links
        if (binTree->li==0)
        {binTree->li=malloc(sizeof(tree));*(binTree->li)=TreeInit;}
        treeIns(binTree->li, key, fcmp);
     }
     else
     {//rechts
        if (binTree->re==0)
        {binTree->re=malloc(sizeof(tree));*(binTree->re)=TreeInit;}
        treeIns(binTree->re, key, fcmp);
     }
   }
}

void dispTree(tree*binTree, void (*f) (int))
{
  if (binTree)
  {
    dispTree(binTree->li,f);
    f(binTree->elem);
    dispTree(binTree->re,f);
  }
}
void disp(int elem)
{
  printf("%d ",elem); 
}

tree* search(tree * sTree, int val)
{
    if(!sTree)
    {
        return NULL;
    }

    if(val < (sTree)->elem)
    {
        search(&(*(sTree)->li), val);
    }
    else if(val > (sTree)->elem)
    {
        search(&(*(sTree)->re), val);
    }
    else if(val == (sTree)->elem)
    {
        return sTree;
    }
}

int elems[]={17,3,57,84,11,9,41,56,1,25};
//int elems[]={4,6,2,15,12,17,9};
int main()
{
  int i,val;
  binTree=malloc(sizeof (tree));
  *binTree=TreeInit;
  searchTree=malloc(sizeof (tree));
  *searchTree=TreeInit;
  for (i=0; elems[i]; i++)
    treeIns(binTree,elems[i],cmpElem);/* packt Baum ein */
  dispTree(binTree,disp);
  printf("\n");
  printf("Geben Sie ein Element, wonach es gesucht sein muss: ");
  scanf("%d",&val);
  searchTree=search(binTree,val);
  if(searchTree)
      printf("Searched node=%d\n", searchTree->elem);
  else printf("gesuchtes Element wurde nicht auf dem Baum gefunden\n");
  //dispTree(searchTree,disp);
  free(searchTree);
  free(binTree);
  return 0;
}