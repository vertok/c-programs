/*  Pre-order displays root node, left node and then right node.
 *    In-order displays left node, root node and then right node.
 *    Post-order displays left node, right node and then root node.*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Tree{
    int key;
    struct Tree *links,*rechts;
}tree;

void addToTree(tree **tBaum, int elem) /* hier geht es nicht mit "tree *tBaum", nur mit **tBaum */
{
    tree *tmp = NULL;
    if(!(*tBaum))
    {
        
        tmp=malloc(sizeof(tree));
        tmp->links = tmp->rechts = NULL;
        tmp->key = elem;
        *tBaum = tmp;
        return;
    }
    if(elem < ((*tBaum)->key))
    {
        addToTree(&(*tBaum)->links, elem); /* Element geht in den linken  TeiltBaum */
    }
    else 
    {
        addToTree(&(*tBaum)->rechts, elem); /* Element geht in den rechten TeiltBaum */
    }    
}

void print_preorder(tree * tBaum)
{
    if(tBaum)
    {
        printf("%d ",tBaum->key);
        print_preorder(tBaum->links);
        print_preorder(tBaum->rechts);
    }
    
}

void print_inorder(tree * tBaum)
{
    if (tBaum)
    {
        print_inorder(tBaum->links);
        printf("%d ",tBaum->key);
        print_inorder(tBaum->rechts);
    }
}

void print_postorder(tree * tBaum)
{
    if (tBaum)
    {
        print_inorder(tBaum->links);
        print_inorder(tBaum->rechts);
        printf("%d ",tBaum->key);
    }
}
int suche(tree *tBaum, int suchElem)
{
    if(!tBaum){ return 0; }
    if(tBaum->key == suchElem) return tBaum->key;
    else if(suchElem < tBaum->key) suche(tBaum->links, suchElem);
    else suche(tBaum->rechts, suchElem);
}

void delTree(tree * tBaum)
{
    if (tBaum)
    {
        delTree(tBaum->links);
        delTree(tBaum->rechts);
        free(tBaum);
    }
}

tree* minElem(tree *tBaum)  /* man braucht die Frunktion um ein min Element in dem rechten Teilbaum zu finden  und durch es zu ersetzen */
{   
    if(tBaum->links)
    {
        tBaum = tBaum->links;
    }
    else;
    return tBaum;
}

tree* del(tree *tBaum, int delElem)
{
    if(!(tBaum))
        return tBaum;
    if(delElem < tBaum->key)
        tBaum->links = del(tBaum->links, delElem);
    else 
        if(delElem > tBaum->key)
            tBaum->rechts = del(tBaum->rechts, delElem); 
        else 
            if((tBaum->links) && (tBaum->rechts))
            {
                tree *tmp=minElem(tBaum->rechts);
                tBaum->key = tmp->key;
                if(tBaum->rechts->links)
                    tBaum->rechts = del(tBaum->rechts,tBaum->rechts->links->key); /* hier loescht man entweder dies Element, falls das Element ueberhaupt existiert */
                    else tBaum->rechts = del(tBaum->rechts,tBaum->rechts->key);        /* oder falls das linken Element rechtes Teilbaums nicht existiert, dann loescht man root des rechten Teilbaums */
            }
            else
                if(tBaum->links)
                    tBaum = tBaum->links;
                else
                    tBaum = tBaum->rechts;
                return tBaum;
}

int height(tree* t)
{
    if (t == NULL)
        return 0;
    else
    {
        if(height(t->links)>height(t->rechts))
            return height(t->links)+1;
        else 
            return height(t->rechts)+1;
    }
}
    
tree* rotateLeft(tree* t)
{ 
    tree *tmp = t->rechts; 
    t->rechts = tmp->links; 
    tmp->links = t; 
    //   temp->height=maximum(heightT(temp->L), heightT(temp->R));
    //t->height=maximum(heightT(t->L), heightT(t->R));
    return tmp;
} 

tree* rotateRight(tree* t)
{ 
    tree *tmp = t->links; 
    t->links = tmp->rechts; 
    tmp->rechts = t; 
    return tmp;
} 

tree* doubleRotateLeft(tree* t)
{ 
    t->rechts = rotateRight(t->rechts);
    tree *tmp = rotateLeft(t); 
    return tmp;
} 


tree* doubleRotateRight(tree* t)
{ 
    t->links = rotateLeft(t->links);
    tree *tmp = rotateRight(t); 
    return tmp;
} 

void balance(tree* t)
{
    if(height(t) == 2){ // right is imbalanced
        if(height(t->rechts) == 1)  
            rotateLeft(t->rechts);
        else 
            if(height(t->rechts) == -1)
                doubleRotateLeft(t->rechts);}
    else{ // must be -2, left is imbalanced
         if(height(t->links) == 1)
             rotateLeft(t->links);
         else
             if(height(t->links) == -1)
                doubleRotateLeft(t->links);}
}

int main()
{
    tree *Baum, *delBaum, *t;
    Baum = NULL; delBaum = NULL;
    int i, a[]={7,3,9,10,8,1,4,2,6,5};
    for(i=0;i<10;i++)
        addToTree(&Baum,a[i]);
    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(Baum);
    
//    printf("\nIn Order Display\n");
//    print_inorder(Baum);
    
//    printf("\nPost Order Display\n");
//    print_postorder(Baum);
    
//    printf("\nGeben Sie ein Element, das Sie finden wollen: ");
//    scanf("%d",&i);
//    if(!suche(Baum,i)) printf("\nElement %d wurde nicht gefunden\n",i);
//    else printf("Gesuchtes Element: %d",suche(Baum,i));
    
//    printf("\nGeben Sie ein Element, das Sie loeschen wollen: ");
//    scanf("%d",&i);
//    delBaum = del(Baum,i);
    /*  Pre-order displays root node, left node and then right node. */
//    print_preorder(delBaum);
    printf("\n");
    balance(Baum);
    


    delTree(Baum);
    delTree(delBaum);
    printf("\n");
    return 0;
}

