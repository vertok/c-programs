/*  Pre-order displays root node, left node and then right node.
    In-order displays left node, root node and then right node.
    Post-order displays left node, right node and then root node.*/
#include<stdlib.h>
#include<stdio.h>


struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

int* make_array(node * tree)
{
    int i=0, a[15];
    while(tree)
    {
        a[i]=tree->data;
        i++;
        a[i]=make_array(tree->left);
        a[i]=make_array(tree->right);
    }
}
        
        

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void del1(node* r, node* q)
{
    if (r->right == NULL)
    {
       //q->key = r->key; // Перенос данных
       q->data = r->data;
       q = r;
       r = r->left;
    }
    else
       del1(r->right, q);
}

void del_node(node* d, int key)
{
    node* q;
    if (d == NULL)
       return;
    else
       if (key < d->data)
          del_node(d->left, key);
       else
          if (key > d->data)
             del_node(d->right, key);
          else
          {
             q = d;
             if (q->right == NULL)
                d = q->left;
             else
                if (q->left == NULL)
                   d = q->right;
                else
                   del1(q->left, q);
             free(q);    // Удаление
          }
}

void main()
{
    node *root; 
    node *tmp;  
    int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);
    
    int *a=make_array(root);
    /* Search node into tree */
   /* printf("geben Sie ein Element, wonach es gesucht sein muss: ");
    scanf("%d",&i);
    tmp = search(&root, i);
    printf("Post Order Display\n");
    print_postorder(tmp);
    
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }*/
    
    printf("\nGeben Sie ein Element, das Sie loeschen wollen:");
    scanf("%d",&i);
    del_node(root, i);
    printf("\nPre Order Display\n");
    print_preorder(root);
    

    /* Deleting all nodes of tree */
    deltree(root);
}