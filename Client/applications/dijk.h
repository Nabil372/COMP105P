#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 17
int graph[V][V] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
														};



int bestpath[V];
int pathsize = 1;

void populateGraph(int *Connected,int size){
	for (int i = 0;i<size;i+=2){
		if (((Connected[i] >= 0)&&(Connected[i+1] >= 0))&&((Connected[i] < V)&&(Connected[i+1] < V))){
			graph[Connected[i]][Connected[i+1]] = 1;
			graph[Connected[i+1]][Connected[i]] = 1;
		}
	}

}
void printArray(int *array,int size){
	for (int i = 0; i < size; i++){
		printf("%d,", array[i]);
	}
	printf("\n");

}

void reverseArray(int *array, int size){
	int i = size - 1;
    int j = 0;
    while(i > j)
    {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    i--;
    j++;
    }    
}

void turnThroughAngle(int angle){
	int ticks = (int) round(angle*0.284);
	printf("%d\n", ticks);
    if (angle > 0)
    {
        drive_goto(-ticks , ticks);
    }
    else
    {
        drive_goto(-ticks , ticks);
    }
}


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
	if (sptSet[v] == 0 && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int src, int target)
{
	int dist[V];	 // The output array. dist[i] will hold the shortest
					// distance from src to i

	int track[V]; //this list stores paths.
	int sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = 0;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V-1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = 1;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++){
			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
				track[v] = u;
			}
		}
	}

	// print the constructed distance array
	//int bestpath[V];
	bestpath[0] = target;
	//int pathsize = 1;
	while (bestpath[pathsize-1] != src){
		bestpath[pathsize] = track[bestpath[pathsize-1]];
		pathsize ++;
	}

	reverseArray(bestpath,pathsize);
	printArray(bestpath,pathsize);
	//driveBack(bestpath,pathsize);
    


}