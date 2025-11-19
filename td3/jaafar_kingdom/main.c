#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 4096

#define V 5

int adj_matrix[V][V] = {{1, 1, 0, 1, 0},
                        {1, 1, 0, 1, 0},
                        {0, 0, 1, 0, 0},
                        {1, 1, 0, 1, 0},
                        {0, 0, 0, 0, 1}};
             
int distance(int matrix[V][V], int m_size, int a, int j);


int main() {
    distance(adj_matrix, V, 1, 3);
    return 0;
}


int distance(int matrix[V][V], int m_size, int a, int j) {
    int visited[m_size];
    int distances[m_size]; 
    for (int i = 0; i < m_size; i++) {
        visited[i] = 0;
        distances[i] = INF;
    }
    distances[a] = 0;

    int queue[m_size];
    int front = 0, rear = 0;
    visited[a] = 1;
    queue[rear++] = a; // Start queue with alladin

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < m_size; v++) {
            if (matrix[u][v] && !visited[v]) {
                visited[v] = 1;
                distances[v] = distances[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    for (int i = 0; i < m_size; i++) {
        printf("Distance from Alladin (%i) to %i: %02i\n", a, i, 
            (distances[i] != INF) ? distances[i] : -1);
    }

    return distances[j];
}
