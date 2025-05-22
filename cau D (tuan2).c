#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

int isHamiltonianCycle(int step, int currentVertex, int n, int adjacency[MAX][MAX], int visited[MAX], int path[MAX]) {
    if (step == n) {
        if (adjacency[currentVertex][path[0]] == 1) {
            return 1;
        }
        return 0;
    }

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adjacency[currentVertex][v] == 1) {
            path[step] = v;
            visited[v] = 1;
            if (isHamiltonianCycle(step + 1, v, n, adjacency, visited, path)) {
                return 1;
            }
            visited[v] = 0;
        }
    }

    return 0;
}

int main() {
    //Tiếp tục hoàn thiện mã nguồn
    int adjacency[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int path[MAX] = {0};
    int n, m;

    FILE *fp = fopen("C:\\Users\\quectkenk\\Desktop\\test\\input7.txt", "r");
    if (fp == NULL) {
        printf("Khong the mo file input5.txt\n");
        return 1;
    }
    
    fscanf(fp, "%d %d", &n, &m);

    // scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);

        // scanf("%d %d", &u, &v);
        adjacency[u][v] = 1;
        adjacency[v][u] = 1;
    }
    fclose(fp);

    for (int i = 1; i <= n; i++) {
        path[0] = i;
        visited[i] = 1;
        if (isHamiltonianCycle(1, i, n, adjacency, visited, path)) {
            for (int j = 0; j < n; j++) {
                printf("%d ", path[j]);
            }
            printf("%d\n", path[0]);
            return 0;
        }
        visited[i] = 0;
    }

    printf("-1\n");
    return 0;
}