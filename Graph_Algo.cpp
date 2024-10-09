#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; // adjacency matrix
int visited[MAX]; // visited nodes array
int numVertices; // number of vertices in the graph

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int numEdges, source, destination;

    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    // Initialize graph and visited arrays
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &source, &destination);
        graph[source][destination] = 1;
        graph[destination][source] = 1; // If the graph is undirected
    }

    printf("Enter the starting vertex: ");
    int startVertex;
    scanf("%d", &startVertex);

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(startVertex);

    return 0;
}
