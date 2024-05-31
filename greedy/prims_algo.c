// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>

#define V 5

int mindis(int key[], bool vis[]){
    int min = INT_MAX,min_ind;
    for(int v = 0; v < V;v++){
        if(key[v] < min && vis[v] == false){
            min = key[v],min_ind = v;
        }
    }
    return min_ind;
}

void printmst(int graph[][V],int parent[]){
    printf("\nThe mst edges are:-");
    for(int i = 1;i < V;i++){
        printf("\n%d - %d = %d",parent[i],i,graph[i][parent[i]]);
    }
}


void primmst(int graph[V][V]){
    bool vis[V];
    int key[V];
    int parent[V];
    
    for (int i = 0; i < V; i++)
		key[i] = INT_MAX, vis[i] = false;

    
    key[0] = 0;
    parent[0] -1;
    
    for(int i = 0;i < V-1;i++){
        int u = mindis(key,vis);
        vis[u] = true;
        for(int v = 0;v < V;v++){
            if(graph[u][v] && !vis[v] && key[v] > graph[u][v]){
                key[v] = graph[u][v],parent[v] = u;
            }
        }
    }
    printmst(graph,parent);
}

int main() {
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	// Print the solution
	primmst(graph);

	return 0;
}