#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

void dfs(int u, int n, int adj[MAX][MAX], int marked[MAX]) {
    marked[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !marked[v]) {
            dfs(v, n, adj, marked);
        }
    }
}

int main() {
    //Tiếp tục hoàn thiện mã nguồn
    // FILE *fp = fopen("C:\\Users\\quectkenk\\Desktop\\test\\input1.txt", "r");
    // if (fp == NULL) {
    //     printf("Khong the mo file.txt\n");
    //     return 1;
    // }
    int n;
    int adj[MAX][MAX];
    int marked[MAX];

    // fscanf(fp, "%d", &n);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // fscanf(fp, "%d", &adj[i][j]);
            scanf("%d", &adj[i][j]);
        }
    }
        
            

    for (int i = 0; i < n; i++)
        marked[i] = 0;

    dfs(0, n, adj, marked);

    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!marked[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("YES\n");
    else
        printf("NO\n");

    // fclose(fp);
    return 0;
}
