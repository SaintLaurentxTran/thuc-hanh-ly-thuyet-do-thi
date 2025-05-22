#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

void dfs(int u, bool marked[], int adjacency[MAX][MAX], int totalVertices) {
    marked[u] = true;
    for (int v = 1; v <= totalVertices; ++v) {
        if (adjacency[u][v] && !marked[v]) {
            dfs(v, marked, adjacency, totalVertices);
        }
    }
}

bool isConnected(int degree[], int adjacency[MAX][MAX], int totalVertices) {
    bool marked[MAX] = {false};
    int start = -1;
    for (int i = 1; i <= totalVertices; ++i) {
        if (degree[i] > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) return true;

    dfs(start, marked, adjacency, totalVertices);
    for (int i = 1; i <= totalVertices; ++i) {
        if (!marked[i] && degree[i] > 0)
            return false;
    }
    return true;
}

void findEuler(int u, int adjacency[MAX][MAX], int path[], int *pathLen, int totalVertices) {
    for (int v = 1; v <= totalVertices; ++v) {
        while (adjacency[u][v]) {
            adjacency[u][v]--;
            adjacency[v][u]--;
            findEuler(v, adjacency, path, pathLen, totalVertices);
        }
    }
    path[(*pathLen)++] = u;
}

int main() {
    // FILE *fp = fopen("C:\\Users\\quectkenk\\Desktop\\test\\input5.txt", "r");
    // if (fp == NULL) {
    //     printf("Khong the mo file input5.txt\n");
    //     return 1;
    // }

    int totalVertices, totalEdges;
    // fscanf(fp, "%d %d", &totalVertices, &totalEdges);

    scanf("%d %d", &totalVertices, &totalEdges);


    int adjacency[MAX][MAX] = {0};
    int degree[MAX] = {0};
    int path[MAX * 2], pathLen = 0;

    for (int i = 0; i < totalEdges; ++i) {
        int u, v;
        // fscanf(fp, "%d %d", &u, &v);
        
        scanf("%d %d", &u, &v);

        adjacency[u][v]++;
        adjacency[v][u]++;
        degree[u]++;
        degree[v]++;
    }
    // fclose(fp);

    for (int i = 1; i <= totalVertices; ++i) {
        if (degree[i] % 2 != 0) {
            printf("No\n");
            return 0;
        }
    }

    if (!isConnected(degree, adjacency, totalVertices)) {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");

    int start = 1;
    while (degree[start] == 0 && start <= totalVertices) start++;
    findEuler(start, adjacency, path, &pathLen, totalVertices);

    for (int i = pathLen - 1; i >= 0; --i) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}
