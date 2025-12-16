//g-graph;v-visited;q-queue

#include<stdio.h>
int g[20][20],v[20],n;
void  BFS(int start){
    int q[20],front=0,rear=0;
    v[start]=1;
    q[rear++]=start;
    while(front<rear){
        int node=q[front++];
        printf("%d",node);
        for(int i=0;i<n;i++){
            if(g[node][i]==1 && !v[i]){
                v[i]=1;
                q[rear++]=i;
            }
        }
    }
}
int main(){
    int start;
    printf("enter no of vertices:");
    scanf("%d",&n);
    printf("enter adj matrix:");
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &g[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
        v[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    BFS(start);
    return 0;
}
