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
    node**adj;
}graph;

graph*creategraph(int V) // V is the number of vertices
{
    graph*g=malloc(sizeof(graph));
    g->v=V;
    g->adj=(node**)malloc(sizeof(node*)*g->v);
    int i=0;
    for(i=0;i<g->v;i++) 
        g->adj[i]=NULL;
    return g;
}

void addedge(graph*g,int u,int v)  // Add v to u’s list.
{
    node*temp=(node*)malloc(sizeof(node));
    temp->val=v;
    temp->next=g->adj[u];
    g->adj[u]=temp;
}

/**
 * This function is a variation of "Depth First Traversal" 
 */
int iscyclutil(graph*g,int v,int visited[],int recstack[]) 
{
    if(visited[v]==0)
    {
        /* Mark all the vertices as not visited and not part of recursion stack */
        visited[v]=1;
        recstack[v]=1;
        node*temp;
        temp=g->adj[v];
        while(temp)
        {
            /* Returns 1 if the graph contains a cycle, else 0. */
            if(!visited[temp->val] && iscyclutil(g,temp->val,visited,recstack))
                return 1;
            else if(recstack[temp->val])
                return 1;
            temp=temp->next;
        }
    }
    recstack[v]=0; // remove the vertex from recursion stack
    return 0;
}

/**
 * the recursive helper function to detect cycle 
 * in different DFS trees
 */
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
    /* Create a graph given in the above diagram */
    graph*g=creategraph(4);
    addedge(g,0, 1);
    addedge(g,0, 2);
    addedge(g,1, 2);
    addedge(g,2, 0);
    addedge(g,2, 3);
    addedge(g,3, 3);
   
    if(Iscycle(g))
        printf("graph has got cycle\n");
    else
        printf("no cycle present in graph\n");
    return 0;
}