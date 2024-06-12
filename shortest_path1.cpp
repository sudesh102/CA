#include <iostream>
#include <vector>
#include <limits.h>
#define MAX 100
#define INFINITY 9999

using namespace std;

void dijkstra(vector<vector<int>>& cost, int n, int start) {
    vector<int> dist(n, INFINITY);
    vector<bool> visited(n, false);
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDistance = INFINITY, nextNode;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDistance) {
                minDistance = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = true;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost[nextNode][i] && dist[nextNode] != INFINITY && dist[nextNode] + cost[nextNode][i] < dist[i]) {
                dist[i] = dist[nextNode] + cost[nextNode][i];
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int n, start;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0) {
                cost[i][j] = INFINITY;
            }
        }
    }

    cout << "Enter the starting node: ";
    cin >> start;

    dijkstra(cost, n, start);

    return 0;
}
