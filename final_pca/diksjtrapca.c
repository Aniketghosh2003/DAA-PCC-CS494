#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define tol_area 5

int mindistance(int distance[], bool sptsset[])
{
    int min = INT_MAX, min_ind;
    for (int i = 0; i < tol_area; i++)
    {
        if (sptsset[i] == false && distance[i] <= min)
        {
            min = distance[i], min_ind = i;
        }
    }
    return min_ind;
}

void printsolution(int dist[tol_area])
{
    printf("\nThe distance from the home :-");
    for (int i = 0; i < tol_area; i++)
    {
        printf("\n%d : %d ", i, dist[i]);
    }
}

void dijktra(int graph[tol_area][tol_area], int src)
{
    int distance[tol_area];
    bool sptset[tol_area];

    for (int i = 0; i < tol_area; i++)
    {
        distance[i] = INT_MAX;
        sptset[i] = false;
    }

    distance[src] = 0;

    for (int i = 0; i < tol_area - 1; i++)
    {
        int u = mindistance(distance, sptset);
        sptset[u] = true;
        for (int v = 0; v < tol_area; v++)
        {
            if (!sptset[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printsolution(distance);
}

int main()
{
    int graph[tol_area][tol_area] = {
        {0, 10, 30, 0, 0},
        {0, 0, 0, 5, 20},
        {0, 0, 0, 0, 0},
        {0, 0, 15, 0, 10},
        {0, 0, 0, 0, 0}};
    dijktra(graph, 0);
    return 0;
}