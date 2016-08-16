#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

bool adj[1001][1001] = { false };
bool visited [1001] = {false};
queue<int> node;
void DFS(const int start);
void BFS(const int start);
int N, M, V;
int main(){
scanf("%d %d %d", &N, &M, &V);
    for( int i = 1 ; i <= M ; ++i ){
        int n1, n2; scanf("%d %d", &n1, &n2);
        adj[n1][n2] = true;
        adj[n2][n1] = true;
    }
    DFS(V);
    printf("\n");
    memset(&visited[1], 0, sizeof(bool)*N);
    BFS(V);
    return 0;
}

void DFS(const int start){
    visited[start]= true;
    printf("%d ", start);
    for ( int i = 1 ; i <= N ; ++i ){
        if( adj[start][i] && !visited[i] ){
            DFS(i);
        }
    }
}

void BFS(const int start){
    int current = start;
    node.push(current);
    visited[current] = true;
    while(1){
        printf("%d ", current);
        for( int i = 1 ; i <= N ; ++i ){
            if( adj[current][i] && !visited[i] ){
                visited[i]= true;
                node.push(i);
            }
        }
        node.pop();
        if(node.empty()) break;
        else current = node.front();
    }
}