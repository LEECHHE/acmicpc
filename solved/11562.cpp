#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n;
int adj[251][251];
int via[251][251];
const int INF = (1<<31)-1;
void floyd(){
    for( int i = 0 ; i <= n ; ++i ){
        adj[i][i] = 0;
    }
    memset(via, -1, sizeof(via));
    for( int k = 1 ; k <= n ; ++k ){
        for( int i = 1 ; i <= n ; ++i ){
            if(adj[i][k] == INF) continue;
            for( int j = 1 ; j <=n ; ++j ){
                if( adj[k][j] == INF ) continue;
                if( adj[i][j] > adj[i][k]+adj[k][j] ){
                    via[i][j] = k;
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }
}
void reconstruct(int u, int v, vector<int>& path){
    if(via[u][v] == -1){
        path.push_back(u);
        if(u!=v) path.push_back(v);
    }
    else{
        int w = via[u][v];
        reconstruct(u, w, path);
        path.pop_back();
        reconstruct(w, v, path);
    }
}
int main(){
    int m; scanf("%d%d",&n,&m);
    for( int i = 0 ; i <= n ; ++i ){
        for( int j = 0 ; j <= n ; ++j ){
            adj[i][j] = INF;
        }
    }
    for( int i = 0 ; i < m ; ++i ){
        int u,v,c; scanf("%d%d%d",&u,&v,&c);
        if( c == 0 ){
            adj[u][v] = 0;
            adj[v][u] = 1;
        }
        else{
            adj[u][v] = adj[v][u] = 0;
        }
    }
    floyd();
    int k; scanf("%d",&k);
    while(k--){
        int a,b; scanf("%d%d",&a,&b);
        vector<int> path;
        reconstruct(a, b, path);
        int len = (int)path.size();
        int ret = 0;
        for( int i = 1 ; i < len ; ++i ){
            ret += adj[a][path[i]];
            a = path[i];
        }
        printf("%d\n", ret);
    }
    return 0;
}