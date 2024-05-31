#include<stdio.h>
#include<limits.h>
#define v 5
#define e 7

void printsolution(int dist[]){
     printf("\nMinimum Distance from source(Jadavpur)");

     for (int i = 0; i < v; i++)
     {
        printf("\n%d : %d",i,dist[i]);
     }
     
}


void bellmanford(int graph[][3],int src){
    int distance[v];

    for (int i = 0; i < v; i++)
    {
        distance[i] =  INT_MAX;
    }

    distance[src] = 0;

    for (int i = 0; i <= v-1; i++)
    {
        for (int j = 0; j < e;j++)
        {
            int u = graph[j][0];
            int V = graph[j][1];
            int wt = graph[j][2];
            if (distance[u] != INT_MAX && distance[u] + wt < distance[V])
            {
                distance[V] = distance[u] + wt;
            }
            
        }
        
    }

    for (int i = 0; i < e; i++)
    {
            int u = graph[i][0];
            int V = graph[i][1];
            int wt = graph[i][2];
            if (distance[u] != INT_MAX && distance[u] + wt < distance[V])
            {
                printf("\n Negative cycle in present in graph , it can't be calculated .");
            }
    }
    
    printsolution(distance);
} 

int main()
{   
    // format is (u , v, wt)
    int graph[][3] = {
        {0, 1, 6},  // Jadavpur to Garia
        {0, 2, 5},  // Jadavpur to Ballygunge
        {2, 3, 4},  // Ballygunge to Rashbihari
        {2, 4, 3},  // Ballygunge to Kalighat
        {3, 4, 3},  // Rashbihari to Kalighat
        {2, 1, 2},  // Ballygunge to Garia (off-peak discount)
        {1, 3, 1}   // Garia to Rashbihari (off-peak discount)
    };
    bellmanford(graph,0);
    return 0;
}