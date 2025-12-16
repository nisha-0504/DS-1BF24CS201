
#include<stdio.h>
#define MAX 10
int visited[MAX],adj[MAX][MAX],n;
void dfs(int v){
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<n;i++){
        if(adj[v][i]==1 && !visited[i]){
            dfs(i);
        }
    }
}
int main(){
    int start;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("DFS Traversal:\n");
    dfs(0);
    return 0;
}



