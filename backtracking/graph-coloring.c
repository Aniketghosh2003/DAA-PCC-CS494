#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int v = 4;

bool issafe(int node,bool graph[v][v],int col,int color[]){
     for (int i = 0; i < v; i++)
	 {
		if(i != node && graph[i][node] && color[i] == col){
			return false;
		}
	 }

	 return true;
	 
}

bool solve(int node,bool graph[v][v],int m,int color[]){
	 if(node == v) return true;

	 for(int i = 1;i <= m;i++){
		if(issafe(node,graph,i,color)){
			color[node] = i;
			if(solve(node+1,graph,m,color)) return true;
			color[node] = 0;
		}
	 }
}

void graphcoloring(bool graph[v][v],int m){
	int color[v];
	memset(color,0,sizeof(color));
	if(solve(0,graph,m,color)){
		printf("\nThe result is :- ");
		for (int i = 0; i < v; i++)
		{
			printf(" %d",color[i]);
		}
		
	}
}

int main()
{
    bool graph[4][4] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3;
    graphcoloring(graph,m);
	return 0;
}