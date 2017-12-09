/*    Pre-order displays root node, left node and then right node.
 *    In-order displays left node, root node and then right node.
 *    Post-order displays left node, right node and then root node.*/
#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) ((i-1) / 2)
#define NUM_NODES 7
#define LINE_WIDTH 80

typedef struct Tree{
    int key;
    struct Tree *links,*rechts;
    int height;
}tree;

int pow_(int x, int y)
{
    int res=1;
    while(y)
    {
        res=res*x;
        y--;
    }
    return res;
}

int height(tree *t);

int max(int a, int b)
{
    return (a > b)? a : b;
}

tree* newNode(int key)
{
    tree* node = (tree*)malloc(sizeof(tree));
    node->key   = key;
    node->links   = NULL;
    node->rechts  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
tree* insert(tree* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));
    
    if (key < node->key)
        node->links  = insert(node->links, key);
    else
        node->rechts = insert(node->rechts, key);
    
    /* 2. Update height of this ancestor node */
    node->height = max(height(node->links), height(node->rechts)) + 1;
    return node;
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


int _print_t(tree *Tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!Tree) return 0;

    sprintf(b, "(%03d)", Tree->key);

    int left  = _print_t(Tree->links,  1, offset,                depth + 1, s);
    int right = _print_t(Tree->rechts, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }

    return left + width + right;
}

int print_t(tree *Tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(Tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}






int * print_inorder1(tree * tBaum,int *a,int i)
{
    //static int i=0;
    if(tBaum)
    {
                
        //i++;
        print_inorder1(tBaum->links,a,2*i+1);
        a[i]=tBaum->key;
        print_inorder1(tBaum->rechts,a,2*i+2);
        //printf("%d ",tBaum->key);

    }
    
    return a;
    
}


void print_tree(int *a)
{
    int print_pos[NUM_NODES];
    int i, j, k, pos, x=1, level=0;
    print_pos[0] = 0;
    for(i=0,j=1; i<NUM_NODES; i++,j++) {
        pos = print_pos[PARENT(i)] + (i%2?-1:1)*(LINE_WIDTH/(pow_(2,level+1))+1);

        for (k=0; k<pos-x; k++) printf("%c",i==0||i%2?' ':'-');
        printf("%d",a[i]);

        print_pos[i] = x = pos+1;
        if (j==pow_(2,level)) {
            printf("\n");
            level++;
            x = 1;
            j = 0;
        }
    }
    printf("\n");
}


char depth[ 2056 ];
int di;
 

void Push( char c )
{
    depth[ di++ ] = ' ';
    depth[ di++ ] = c;
    depth[ di++ ] = ' ';
    depth[ di++ ] = ' ';
    depth[ di ] = 0;
}
 
void Pop( )
{
    depth[ di -= 4 ] = 0;
}


void Print( tree* Tree )
{
    printf( "(%d)\n", Tree->key );
 
    if ( Tree->links )
    {
        printf( "%s `--", depth );
        Push( '|' );
        Print( Tree->links );
        Pop( );
 
        printf( "%s `--", depth );
        Push( ' ' );
        Print( Tree->rechts );
        Pop( );
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

int height(tree *t)
{
    if (t == NULL)
        return 0;
    return t->height;
}

tree* rotateLeft(tree* t)
{ 
    tree *y = t->rechts;
    tree *T2 = y->links;
    
    // Perform rotation
    y->links = t;
    t->rechts = T2;
    
    
    // Update heights
    t->height = max(height(t->links), height(t->rechts))+1;
    y->height = max(height(y->links), height(y->rechts))+1;
    
    // Return new root
    return y;
} 

tree* rotateRight(tree* t)
{ 
    tree *x = t->links;
    tree *T2 = x->rechts;
    
    // Perform rotation
    x->rechts = t;
    t->links = T2;
    
    // Update heights
    t->height = max(height(t->links), height(t->rechts))+1;
    x->height = max(height(x->links), height(x->rechts))+1;
    
    // Return new root
    return x;
} 

int getBalance(tree *t)
{
    if(t==NULL)
        return 0;
    return height(t->links)-height(t->rechts);
}

tree *balanceNode(tree *t)
{
    if (!t) return t;
    int balance = getBalance(t);
    if (balance > 1 && getBalance(t->links) >= 0)   /* rotateRight */
        return rotateRight(t);
    if (balance < -1 && getBalance(t->rechts) <= 0) /* rotateLeft */
        return rotateLeft(t);
    if (balance > 1 && getBalance(t->links) < 0)    /* rotateLeftRight */
    {
        t->links = rotateLeft(t->links);
        return rotateRight(t);
    }
    if (balance < -1 && getBalance(t->rechts) > 0)  /* rotateRightLeft */
    {
        t->rechts = rotateRight(t->rechts);
        return rotateLeft(t);
    }
    return t;
}


int main()
{
    tree *Baum;
    Baum = NULL; 
    int *qwe;
    char vBuf[128];
    int i,j, a[]={4,2,11,7,3,5,1};//a[]={7,10,9,11,8,1,6,5};
    int NUM=2*(sizeof(a)/sizeof(a[0]));
    printf("\n%d\n",NUM);
    for(i=0;i<NUM;i++)qwe[i]=0;
    for(i=0;i<NUM/2;i++)
        Baum = insert(Baum,a[i]);
    print_t(Baum);
    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(Baum);
    printf("\n");
     //   Print(Baum);
    printf("\nBalanced Tree\n");
    Baum=balanceNode(Baum);
            //Print(Baum);
        print_t(Baum);

int pruf,k=0; 
    print_preorder(Baum);
    qwe[0]=Baum->key;
    qwe=print_inorder1(Baum,qwe,0);
 
    i=0;
    int *arr;int i1=0;
    int ttt;
    while(i<NUM)
    {
        ttt=qwe[i];
        for(j=0;j<NUM/2;j++)
            if(ttt==a[j])
            {
                arr[i1]=ttt;
                i1++;
                break;
                
            }
            i++;
    }
    i1--;
    
    
   /* while(i<NUM){
        pruf=0;
        //printf("\naaa%d",pruf);
        for(j=0;j<NUM/2;j++)
            if(qwe[i]==a[j])
            {
                printf("qqq%d=%dqqq",qwe[i],a[j]);
                pruf=1;
                
            }
         //   printf("\nppp%d",pruf);
        if(pruf==0){
           // printf("fg");
            for(k=i;k<NUM-1;k++)
                qwe[k]=qwe[k+1];

            }
        i++;
    }*/
    for(i=0;i<NUM/2;i++)
        printf("\n%d",arr[i]);
    
    //    printf("\nGeben Sie ein Element, das Sie finden wollen: ");
    //    scanf("%d",&i);
    //    if(!suche(Baum,i)) printf("\nElement %d wurde nicht gefunden\n",i);
    //    else printf("Gesuchtes Element: %d",suche(Baum,i));
    /*  Pre-order displays root node, left node and then right node. */
   // printf("\nwenn Sie das Programm verlassen wollen, tippen Sie q ein, \nsonst geben Sie ein Element zum loeschen ein:\n");
   /* while(i)
    {
        fgets(vBuf,128,stdin);
        if(vBuf[0]=='q') break;
        j=atoi(vBuf);
        Baum = del(Baum,j);
        Baum = balanceNode(Baum);
      //  print_preorder(Baum);
        printf("\n");
        i--;
    }*/
       print_t(Baum);

    printf("\n");
    print_tree(arr);
    delTree(Baum);
    return 0;
}

