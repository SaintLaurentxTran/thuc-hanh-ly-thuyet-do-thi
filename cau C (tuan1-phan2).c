#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 55

void dfs(int currentNode, int nodeCount, int adjMatrix[MAX][MAX], int marked[MAX]) {
    marked[currentNode] = 1;
    for (int neighbor = 1; neighbor <= nodeCount; neighbor++) {
        if (adjMatrix[currentNode][neighbor] && !marked[neighbor]) {
            dfs(neighbor, nodeCount, adjMatrix, marked);
        }
    }
}

int main() {
    int nodeCount, edgeCount;
    int edgeList[MAX][2];
    int adjMatrix[MAX][MAX];
    int marked[MAX];

    // FILE *fp = fopen("C:\\Users\\quectkenk\\Desktop\\test\\input3.txt", "r");
    // if (fp == NULL) {
    //     printf("Khong the mo file input.txt\n");
    //     return 1;
    // }

    // fscanf(fp, "%d %d", &nodeCount, &edgeCount);
    scanf("%d %d", &nodeCount, &edgeCount);

    for (int i = 1; i <= edgeCount; i++) {
        // fscanf(fp, "%d %d", &edgeList[i][0], &edgeList[i][1]);
        scanf("%d %d", &edgeList[i][0], &edgeList[i][1]);

    }

    int queryCount;
    // fscanf(fp, "%d", &queryCount);
    scanf("%d", &queryCount);

    for (int q = 0; q < queryCount; q++) {
        int left, right;
        // fscanf(fp, "%d %d", &left, &right);
        scanf("%d %d", &left, &right);


        memset(adjMatrix, 0, sizeof(adjMatrix));
        for (int i = 1; i <= edgeCount; i++) {
            if (i < left || i > right) {
                int u = edgeList[i][0];
                int v = edgeList[i][1];
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1;
            }
        }

        memset(marked, 0, sizeof(marked));
        int componentCount = 0;
        for (int i = 1; i <= nodeCount; i++) {
            if (!marked[i]) {
                dfs(i, nodeCount, adjMatrix, marked);
                componentCount++;
            }
        }
        printf("%d\n", componentCount);
    }

    // fclose(fp);
    return 0;
}
