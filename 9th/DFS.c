#include <stdio.h>

int n, a[10][10], visited[10];

void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d",v);
    for (i = 0; i < n; i++)
        if (a[v][i] == 1 && visited[i] == 0)
            dfs(i);
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    dfs(0);

    for (i = 0; i < n; i++)
        if (visited[i] == 0)
        {
            printf("Graph is NOT connected");
            return 0;
        }

    printf("Graph is CONNECTED");
    return 0;
}

