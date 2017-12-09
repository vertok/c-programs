#define N 30
    char Buchstaben[N]={'I','A',
                        'A','I','B','C',
                        'B','A','F','O',
                        'C','A','D','E',
                        'D','C','F','E',
                        'E','C','D','O',
                        'F','B','D','O',
                        'O','B','E','F'};

int count=0;
while(count<N){
    //fühlt unser Labirinth aus
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]=Buchstaben[count]; x->name[1]='\0';
    count++;
    y->name[0]=Buchstaben[count]; y->name[1]='\0';
    count++;
    x->next=y;
if(count==2){//da am Anfang steht es mazestruc in ersten Reihe               
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=x;
    mazestruc=mlist1;
    }
else{
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]=Buchstaben[count]; x->name[1]='\0';
    count++;
    y->name[0]=Buchstaben[count]; y->name[1]='\0';
    count++;
    x->next=y;
    y1->next=x;
    mlist1=malloc(sizeof(struct connect));
    mlist1->nlist=anker2;
    mlist2->next=mlist1;
}
    //-----------------------------------
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]=Buchstaben[count]; x->name[1]='\0';
    count++;
    y->name[0]=Buchstaben[count]; y->name[1]='\0';
    count++;
    x->next=y;
    y1=y;
    anker2=x;
    x=malloc(sizeof(struct nodeitem));
    y=malloc(sizeof(struct nodeitem));
    x->name[0]=Buchstaben[count]; x->name[1]='\0';
    count++;
    y->name[0]=Buchstaben[count]; y->name[1]='\0';
    count++;
    x->next=y;
    y1->next=x;
    mlist2=malloc(sizeof(struct connect));
    mlist2->nlist=anker2;
    mlist1->next=mlist2;
    }
