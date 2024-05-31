#include<stdio.h>
#define v 5
#define INF 99999

void floydwarshall(int graph[][v]){
     for (int k = 0; k < v; k++)
     {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
                
            }
            
        }
        
     }

     printSolution(graph);
}

void printSolution(int graph[][v]) {
    printf("Shortest distances between distribution centers:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (graph[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int distance[][v] = {
        {0, 10, INF, 30, INF},  // DC1
        {10, 0, 5, INF, 20},  // DC2
        {INF, 5, 0, 15, 10},  // DC3
        {30, INF, 15, 0, INF},  // DC4
        {INF, 20, 10, INF, 0}   // DC5
    };

    floydwarshall(distance);
    return 0;
}
