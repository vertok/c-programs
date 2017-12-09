#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int elem;
    struct node* next;
}Node;

typedef struct list
{
    Node* first;
    Node* last;
}List;
 
void initializeList(List* lst)
{
    lst->first = NULL;
    lst->last = NULL;
}
 
void push_tail(List* lst, int numb)  /* ein Element am Ende der Liste setzen */
{
    Node* t = (Node*) malloc(sizeof(Node));
    t->elem = numb;
    t->next = NULL;
    if(lst->first == NULL)
    {
       lst->first = t;
       lst->last = t;
       return;
    }
    lst->last->next = t;
    lst->last = t;
}

void push_head(List * lst, int numb)  /* ein Element am Anfang der Liste setzen */
{
    Node* t = (Node*) malloc(sizeof(Node));
    t->elem = numb;
    t->next = lst->first;
    lst->first = t;
    
}

void free_list(List* lst)
{
    lst->last = lst->first;
    while(lst->first)
    {
       lst->first = lst->first->next;
       free(lst->last);
       lst->last = lst->first;
    }
}

void print_list(List* lst)
{
    for(Node* tmp = lst->first; tmp; tmp = tmp->next)
        printf("%d ", tmp->elem);
}

int member(List* l, int num) /* prueft ob eine Zahl in der Liste stattfindet */
{
    Node* t=(Node* ) malloc(sizeof(Node));
    t=l->first;
    while(t != NULL){
        if(t->elem == num)
        {
            return 1;
            break;
        }
        t = t->next;
    }
    return 0;    
}


/*void dur( List* l1, List* l2) // Durchschnitt von zwei Mengen
{
    printf("Menge A n B = ");
    Node* tmp1=(Node*) malloc(sizeof(Node));
    Node* tmp2=(Node*) malloc(sizeof(Node));
    tmp2=l2->first;tmp1=l1->first;
    while((tmp1 != NULL) && (tmp2 != NULL)){
           if(tmp1->elem < tmp2->elem)
                tmp1 = tmp1->next;
            else if(tmp2->elem < tmp1->elem)
                tmp2 = tmp2->next;
            else {
                printf("%d ",tmp1->elem);
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
    }
}*/
/*void dif( List* l1, List* l2) // Differenz von 2 Mengen
{
    printf("Menge A / B = ");
    int i;
    Node* tmp1=(Node*) malloc(sizeof(Node));
    Node* tmp2=(Node*) malloc(sizeof(Node));
        for( tmp1 = l1->first; tmp1; tmp1 = tmp1->next)
        {
            i=0;
        for( tmp2 = l2->first; tmp2; tmp2 = tmp2->next)
        {
          if((tmp1->elem)==(tmp2->elem))
            i=1;
        }
        if(i!=1) printf("%d ", tmp1->elem);
        }
}*/

List dur( List* l1, List* l2) /* Durchschnitt von 2 Mengen */
{
    List l;
    initializeList(&l);
    printf("Menge A n B = ");
    Node* t=(Node*) malloc(sizeof(Node));
        for( t = l2->first; t; t = t->next)
          if(member(l1,t->elem))
                push_tail(&l,t->elem);
   return l;     
}

List dif( List* l1, List* l2) /* Differenz von 2 Mengen */
{
    List l;
    initializeList(&l);
    printf("Menge A / B = ");
    Node* t=  (Node*) malloc(sizeof(Node));
        for( t = l1->first; t; t = t->next)
          if(!(member(l2,t->elem)))
              push_tail(&l, t->elem);  
    return l;
}

List ver( List* l1, List* l2) /* Vereinigung von 2 Mengen */
{
    List l;
    initializeList(&l);
    printf("Menge A U B = ");
    Node* t=  (Node*) malloc(sizeof(Node));
        for( t = l1->first; t; t = t->next)  /* man schreibt alle Elemente, die nur in der ersten Menge sind */
          if(!(member(l2,t->elem)))
              push_tail(&l, t->elem);  
        for( t = l2->first; t; t = t->next)  /* dann schreibt man einfach noch die zweite Menge dazu */
              push_tail(&l,t->elem);
    return l;
}


/*void ver( List* l1, List* l2)  // Vereinigung von 2 Mengen 
{
    printf("Menge A U B = ");
    Node* tmp1=malloc(sizeof(l1)*sizeof(Node));
    Node* tmp2=malloc(sizeof(l2)*sizeof(Node));
    tmp2=l2->first;tmp1=l1->first;
        while((tmp1 != NULL) && (tmp2 != NULL)){
            if(tmp1->elem < tmp2->elem){
                printf("%d ",tmp1->elem);
                tmp1 = tmp1->next;
            } else if(tmp2->elem < tmp1->elem){
                printf("%d ",tmp2->elem);
                tmp2 = tmp2->next;
            } else {
                printf("%d ",tmp1->elem);
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }
        for(; tmp1 != NULL; tmp1 = tmp1->next)
            printf("%d ",tmp1->elem);
        for(; tmp2 != NULL; tmp2 = tmp2->next)
            printf("%d ",tmp2->elem);
    
}*/
int main()
{
    List lst,lst2,l; 
    initializeList(&lst);/* hier wird die erste Menge eingegeben */
    push_head (&lst, 7);
    push_head (&lst, 5);
    push_head (&lst, 3);
    push_head (&lst, 2);
    push_head (&lst, 1);
    printf("Menge A: ");
    print_list(&lst);
printf("\n");    
    initializeList(&lst2);/* hier wird die zweite Menge eingegeben */
    push_tail (&lst2, 2);
    push_tail (&lst2, 3);
    push_tail (&lst2, 4);
    push_tail (&lst2, 7);
    printf("Menge B: ");
    print_list(&lst2);
printf("\n");  
    l=dur(&lst,&lst2); /* Ausgabe "Durchschnitt von zwei Mengen" */
    print_list(&l);
    free_list(&l);
printf("\n"); 
    l=dif(&lst,&lst2); /* Ausgabe "Difference von zwei Mengen" */
    print_list(&l);
    free_list(&l);
printf("\n"); 
    l=ver(&lst,&lst2); /* Ausgabe "Vereinigung von zwei Mengen" */
    print_list(&l);
    free_list(&l);
free_list(&lst); 
free_list(&lst2); 
printf("\n"); 

}