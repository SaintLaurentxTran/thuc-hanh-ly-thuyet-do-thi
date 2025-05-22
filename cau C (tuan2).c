#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

void removeEdge(int u, int v, int adjacency[MAX][MAX]) {
    adjacency[u][v]--;
    adjacency[v][u]--;
}

void addToPath(int vertex, int path[], int *pathLength) {
    path[*pathLength] = vertex;
    (*pathLength)++;
}

int findStartVertex(int degree[], int totalVertices) {
    int oddCount = 0;
    int oddVertex = 1;

    for (int i = 1; i <= totalVertices; i++) {
        if (degree[i] % 2 != 0) {
            oddCount++;
            oddVertex = i;
        }
    }

    if (oddCount == 0 || oddCount == 2) {
        return oddVertex;
    }

    return -1;
}

void dfsEuler(int u, int totalVertices, int adjacency[MAX][MAX], int path[], int *pathLength) {
    for (int v = 1; v <= totalVertices; v++) {
        while (adjacency[u][v] > 0) {
            removeEdge(u, v, adjacency);
            dfsEuler(v, totalVertices, adjacency, path, pathLength);
        }
    }
    addToPath(u, path, pathLength);
}

int main() {
    int adjacency[MAX][MAX] = {0};
    int degree[MAX] = {0};
    int path[MAX * MAX];
    int totalVertices, totalEdges, pathLength = 0;

    FILE *fp = fopen("C:\\Users\\quectkenk\\Desktop\\test\\input6.txt", "r");
    if (fp == NULL) {
        printf("Khong the mo file input5.txt\n");
        return 1;
    }
    fscanf(fp, "%d %d", &totalVertices, &totalEdges);

    // scanf("%d %d", &totalVertices, &totalEdges);

    for (int i = 0; i < totalEdges; i++) {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);

        // scanf("%d %d", &u, &v);
        adjacency[u][v]++;
        adjacency[v][u]++;
        degree[u]++;
        degree[v]++;
    }

    int startVertex = findStartVertex(degree, totalVertices);
    if (startVertex == -1) {
        printf("No\n");
        return 0;
    }

    dfsEuler(startVertex, totalVertices, adjacency, path, &pathLength);

    if (pathLength != totalEdges + 1) {
        printf("No\n");
    } else {
        printf("Yes\n");
        for (int i = pathLength - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }

    return 0;
}
