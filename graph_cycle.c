#include<stdio.h>

#include<stdlib.h>

typedef struct Node

{
    
    int val;
    
    struct Node*next;
    
}node;

typedef struct Graph

{
    
    int v;
    
    node** adj;
    
}graph;

graph*creategraph(int V)

{
    int v;
    node** adj;
    graph*g=malloc(sizeof(graph));
    
    g->v=V;
    
    g->adj=(node**)malloc(sizeof(node*)*g->v);
    
    int i=0;
    
    for(i=0;i<v;i++) g->adj[i]=NULL;
    
    return g;
    
}

void addedge(graph*g,int u,int v)

{
    
    node*temp=(node*)malloc(sizeof(node));
    
    temp->val=v;
    
    temp->next=g->adj[u];
    
    g->adj[u]=temp;
    
}

int iscyclutil(graph*g,int v,int visited[],int recstack[])

{
    
    if(visited[v]==0)
        
    {
        
        visited[v]=1;
        
        recstack[v]=1;
        
        node*temp;
        
        temp=g->adj[v];
        
        while(temp)
            
        {
            
            if(!visited[temp->val] && iscyclutil(g,temp->val,visited,recstack))
                
                return 1;
            
            else if(recstack[temp->val])
                
                return 1;
            
            temp=temp->next;
            
        }
        
    }
    
    recstack[v]=0;
    
    return 0;
    
}

int Iscycle(graph*g)

{
    
    int recstack[g->v];
    
    int visited[g->v];
    
    int i;
    
    for(i=0;i<g->v;i++)
        
    {
        
        visited[i]=0;
        
        recstack[i]=0;
        
    }
    
    for(i=0;i<g->v;i++)
        
    {
        
        if(iscyclutil(g,i,visited,recstack))
            
            return 1;
        
    }
    
    return 0;
    
}

int main()

{
    
    graph*g=creategraph(3);
    
    addedge(g,0,1);
    
    addedge(g,4,2);
    
    addedge(g,3,5);
    
    if(Iscycle(g))
        
        printf("graph has got cycle\n");
    
    else
        
        printf("no cycle present in graph\n");
    
    return 0;
    
}