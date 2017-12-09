#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int n;    // Denotes number of nodes in the graph 

void create_graph()
{
    int i,max_edges,origin,destin;
    
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    max_edges=n*(n-1);
    
    for(i=1;i<=max_edges;i++)
    {
        printf("Enter edge %d( 0 0 to quit ) : ",i);
        scanf("%d %d",&origin,&destin);
        
        if((origin==0) && (destin==0))
            break;
        
        if( origin > n || destin > n || origin<=0 || destin<=0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin]=1;
        }
    }// End of for
}// End of create_graph()

void display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }
}// End of display()

int main()
{
    int i,v,choice;
    create_graph();
    printf("Adjacency Matrix\n");
    display();
    
    return 0;
}// End of main()