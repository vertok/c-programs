#include <stdio.h>
#include <stdlib.h>
typedef struct nodeitem *pnodelist;
        struct nodeitem {char name[2];
                         pnodelist next;
                        };
        typedef struct connect *pconnect;
                struct connect {pnodelist nlist;
                                pconnect next;
                               };


pnodelist maz(pconnect lab, pnodelist ins, char out, pnodelist way);
pnodelist maze(pconnect lab, char in, char out, pnodelist way);

void writelist(pnodelist l){
    if(l!=NULL){
        printf("%c ", l->name[0]);
        writelist(l->next);
    }
    else
        printf("\n");
}

void writemaze(pconnect l){
    if(l!=NULL){
        writelist(l->nlist);
        printf("\n");
        writemaze(l->next);
    }
    else
        printf("\n");
}

pnodelist assoc(char i, pconnect xlist){
    if(xlist==NULL)
        return NULL;
    else
        if(xlist->nlist->name[0]==i)
            return xlist->nlist;
        else
            return assoc(i,xlist->next);
}
pnodelist member(char i, pnodelist nlist){
    if(nlist==NULL)
        return NULL;
    else
        if(nlist->name[0]==i)
            return nlist;
        else
            return member(i, nlist->next);
}


pnodelist cons( char x, pnodelist list){
    pnodelist n=malloc(sizeof(struct nodeitem));
    n->name[0]=x;
    n->name[1]='\n';
    n->next=list;
    return n;
}

pnodelist or2(pnodelist x, pnodelist y){
    if(x==NULL){
        if(y==NULL)
            return NULL;
        else
            return y;
    }
    else
        return x;
}

int main(){
    /*char Buchstaben[N]={'I','A',
                        'A','I','B','C',
                        'B','A','F','O',
                        'C','A','D','E',
                        'D','C','F','E',
                        'E','C','D','O',
                        'F','B','D','O',
                        'O','B','E','F'};*/
    /*char Buchstaben[N]={'I','A',
                        'A','I','B','C',
                        'B','A',
                        'C','A','D','E',
                        'D','C',
                        'E','F','K','J','C',
                        'F','G','E','H',
                        'G','H',
                        'H','F','I','J',
                        'I','H',
                        'J','E','H','O',
                        'K','E',
                        'O','J'};*/
    pconnect mazestruc;
    pconnect mlist1;
    pconnect mlist2;
    pnodelist x;
    pnodelist y;
    pnodelist y1;
    pnodelist anker2;
    
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='I'; x->name[1]='\0';
    y->name[0]='A'; y->name[1]='\0';
    x->next=y;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=x;
    mazestruc=mlist1;
    //-------------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='A'; x->name[1]='\0';
    y->name[0]='I'; y->name[1]='\0';
    x->next=y;
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='B'; x->name[1]='\0';
    y->name[0]='C'; y->name[1]='\0';
    x->next=y;
    y1->next=x;
    mlist2=malloc(sizeof(struct connect));
    mlist2->nlist=anker2;
    mlist1->next=mlist2;
    //------------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='B'; x->name[1]='\0';
    y->name[0]='A'; y->name[1]='\0';
    x->next=y;
    anker2=x;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=anker2;
    mlist2->next=mlist1;
    //----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='C'; x->name[1]='\0';
    y->name[0]='A'; y->name[1]='\0';
    x->next=y;
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='D'; x->name[1]='\0';
    y->name[0]='E'; y->name[1]='\0';
    x->next=y;
    y1->next=x;
    mlist2=malloc(sizeof(struct connect));
    mlist2->nlist=anker2;
    mlist1->next=mlist2;
    //-------------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='D'; x->name[1]='\0';
    y->name[0]='C'; y->name[1]='\0';
    x->next=y;
    anker2=x;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=anker2;
    mlist2->next=mlist1;
    //-------------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='E'; x->name[1]='\0';
    y->name[0]='F'; y->name[1]='\0';
    x->next=y;
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='K'; x->name[1]='\0';
    y->name[0]='J'; y->name[1]='\0';
    x->next=y;
    y1->next=x;
    x=malloc(sizeof(struct nodeitem));
    x->name[0]='C'; x->name[1]='\0';
    x->next=y;
    //anker2=x;
    mlist2=malloc(sizeof(struct connect));
    mlist2->nlist=anker2;
    mlist1->next=mlist2;
    //-----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='F'; x->name[1]='\0';
    y->name[0]='G'; y->name[1]='\0';
    x->next=y;
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='E'; x->name[1]='\0';
    y->name[0]='H'; y->name[1]='\0';
    x->next=y;
    y1->next=x;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=anker2;
    mlist2->next=mlist1;
    //-----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='G'; x->name[1]='\0';
    y->name[0]='H'; y->name[1]='\0';
    x->next=y;
    anker2=x;
    mlist2=malloc(sizeof(struct connect));
    mlist2->nlist=anker2;
    mlist1->next=mlist2;  
    //----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='H'; x->name[1]='\0';
    y->name[0]='F'; y->name[1]='\0';
    x->next=y;
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='I'; x->name[1]='\0';
    y->name[0]='J'; y->name[1]='\0';
    x->next=y;
    y1->next=x;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=anker2;
    mlist2->next=mlist1;
    //----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='I'; x->name[1]='\0';
    y->name[0]='H'; y->name[1]='\0';
    x->next=y;
    anker2=x;
    mlist2=malloc(sizeof(struct connect));
    mlist2->nlist=anker2;
    mlist1->next=mlist2;
    //----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='J'; x->name[1]='\0';
    y->name[0]='E'; y->name[1]='\0';
    x->next=y;
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='H'; x->name[1]='\0';
    y->name[0]='O'; y->name[1]='\0';
    x->next=y;
    y1->next=x;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=anker2;
    mlist2->next=mlist1;
    //----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='K'; x->name[1]='\0';
    y->name[0]='E'; y->name[1]='\0';
    x->next=y;
    anker2=x;
    mlist2=malloc(sizeof(struct connect));
    mlist2->nlist=anker2;
    mlist1->next=mlist2;
    //----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]='O'; x->name[1]='\0';
    y->name[0]='J'; y->name[1]='\0';
    x->next=y;
    anker2=x;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=anker2;
    mlist2->next=mlist1;
    //----------------------------------
    printf("Suche im Labyrinth:\n");
    writemaze(mazestruc);
    printf("-------------------\n");
    printf("===================\n");
    writelist(maze(mazestruc,'I','O',NULL));
    return 0;
}

pnodelist maze(pconnect lab, char in, char out, pnodelist way){
    printf("--now in maze --\n");
    printf("      in: %c\n",in);
    printf("      way: ");writelist(way);printf("\n");
    return maz(lab,assoc(in,lab)->next,out,cons(in,way));
}

pnodelist maz(pconnect lab, pnodelist ins, char out, pnodelist way){
    printf("      in maz \n");
    writelist(way);
    if(ins==NULL)
        return NULL;
    else
        if(ins->name[0]==out)
            return cons(out,way);
        else
            if(member(ins->name[0],way)!=NULL)
                return maz(lab,ins->next,out,way);
            else
                return or2(maze(lab,ins->name[0],out,way),
                            maz(lab,ins->next,out,way));
}