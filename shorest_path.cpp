#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INFINITY 9999
void dijkstra(int cost[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX], count, minDistance, nextNode, i, j;
    // Initialization
    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1) {
        minDistance = INFINITY;
        // Choose the next node
        for (i = 0; i < n; i++) {
            if (dist[i] < minDistance && !visited[i]) {
                minDistance = dist[i];
                nextNode = i;
            }
        }   
        visited[nextNode] = 1;
        
        // Update distances
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (minDistance + cost[nextNode][i] < dist[i]) {
                    dist[i] = minDistance + cost[nextNode][i];
                }
            }
        }
        count++;
    }   
    // Print the distance to each node
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    int cost[MAX][MAX], n, i, j, start;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INFINITY;
            }
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &start);
    dijkstra(cost, n, start);   
    return 0;
}