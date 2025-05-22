#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void dfs(int top, int n, int adj[MAX][MAX], bool marked[MAX], int components[MAX], int *size) {
    marked[top] = true;
    components[*size] = top;
    (*size)++;
    for (int i = 1; i <= n; i++) {
        if (adj[top][i] && !marked[i]) {
            dfs(i, n, adj, marked, components, size);
        }
    }
}

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


int main() {
    //Tiếp tục hoàn thiện mã nguồn
    // FILE *fp = fopen("C:\\Users\\quectkenk\\Desktop\\test\\input2.txt", "r");
    // if (fp == NULL) {
    //     printf("Khong the mo file.txt\n");
    //     return 1;
    // }
    int n, edge;
    // fscanf(fp, "%d %d", &n, &edge);
    scanf("%d %d", &n, &edge);


    int adj[MAX][MAX] = {0};
    bool marked[MAX] = {false};
    int components[MAX];
    int size = 0;

    int partCom[MAX][MAX];
    int componentsSize[MAX];

    for (int i = 0; i < edge; i++) {
        int u, v;
        // fscanf(fp, "%d %d", &u, &v);
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int total = 0;

    for (int i = 1; i <= n; i++) {
        if (!marked[i]) {
            size = 0;
            dfs(i, n, adj, marked, components, &size);

            sort(components, size);

            for (int j = 0; j < size; j++) {
                partCom[total][j] = components[j];
            }
            componentsSize[total] = size;
            total++;
        }
    }

    printf("%d\n", total);
    for (int i = 0; i < total; i++) {
        printf("%d", componentsSize[i]);
        for (int j = 0; j < componentsSize[i]; j++) {
            printf(" %d", partCom[i][j]);
        }
        printf("\n");
    }
    // fclose(fp);
    return 0;
}
