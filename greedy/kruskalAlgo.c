#include<stdio.h>
#include<stdlib.h>

#define V 5

int cmp(const void*a, const void*b){
    const int(*x)[3] = a;
    const int(*y)[3] = b;

    return (*x)[2] - (*y)[2];
}

int findparent(int parent[],int node){
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findparent(parent,parent[node]);
    
}

void unionbyrank(int u,int v,int parent[],int rank[],int n){
     int ulp_u = findparent(parent,u);
     int ulp_v = findparent(parent,v);

     if(rank[ulp_u] > rank[ulp_v]){
        parent[ulp_v] = ulp_u;
     }

     else if(rank[ulp_v] > rank[ulp_u]){
        parent[ulp_u] = ulp_v;
     }
     else
     {
        parent[ulp_u] = ulp_v;
        rank[ulp_v]++;
     }
     
}

void kruskalAlgo(int n,int graph[n][3]){
    qsort(graph,n,sizeof(graph[0]),cmp);

    int rank[n];
    int parent[n];

    for (int i = 0; i < n; i++)
    {
        parent[i] = i,rank[i] = 0;
    }
    

    int mincost = 0;

    printf("\nMst is :- ");
    
    for (int i = 0; i < n; i++)
    {
        int v1 = findparent(parent,graph[i][0]);
        int v2 = findparent(parent,graph[i][1]);
        int wt = graph[i][2];

        if (v1 != v2)
        {
            mincost += wt;
            unionbyrank(v1,v2,parent,rank,n);
            printf("\n%d - %d -> %d",graph[i][0],graph[i][1],wt);
        }
        
    }
    
    printf("\nMinimum cost is :- %d",mincost);

}

int main()
{
    int edge[5][3] = {{0, 1, 10},
					  {0, 2, 6},
					  {0, 3, 5},
					  {1, 3, 15},
					  {2, 3, 4}};

	kruskalAlgo(5, edge);
    return 0;
}