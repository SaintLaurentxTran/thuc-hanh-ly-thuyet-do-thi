#include <stdio.h>
#define MAX 100

int main() {
    int n, m;
    int degree[MAX] = {0};

    // FILE *fp = fopen("C:\\Users\\quectkenk\\Desktop\\test\\input4.txt", "r");
    // if (fp == NULL) {
    //     printf("Khong the mo file input.txt\n");
    //     return 1;
    // }

    // fscanf(fp, "%d %d", &n, &m);
    scanf("%d %d", &n, &m);
    

    for (int i = 0; i < m; i++) {
        int u, v;
        // fscanf(fp, "%d %d", &u, &v);
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", i, degree[i]);
    }

    return 0;
}
