#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int adj[101][101];
const int INF = 987654321;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            if( i == j ) continue;
            adj[i][j] = INF;
        }
    }
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[a][b] = adj[b][a] = 1;
    }
    int group[101] = { 0 };
    int cnt = 0;
    for( int i = 1 ; i <= n ; ++i ){
        if( group[i] > 0 ) continue;
        ++cnt;
        queue<int> q;
        q.push(i);
        group[i] = cnt;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for( int next = 1 ; next <= n ; ++next ){
                if( group[next] > 0 ) continue;
                if( adj[cur][next] == INF ) continue;
                group[next] = cnt;
                q.push(next);
            }
        }
    }
    
    for( int k = 1 ; k <= n ; ++k ){
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 1 ; j <= n ; ++j ){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    vector<int> ans(cnt);
    vector<int> values(cnt,INF);
    for( int i = 1 ; i <= n ; ++i ){
        int _max = 0;
        for( int j = 1 ; j <= n ; ++j ){
            if( adj[i][j] < INF ){
                _max = max(_max, adj[i][j]);
            }
        }
        if( values[group[i]-1] > _max ){
            values[group[i]-1] = _max;
            ans[group[i]-1] = i;
        }
    }
    printf("%d\n", cnt);
    sort(ans.begin(), ans.end());
    for( auto a : ans ){
        printf("%d\n", a);
    }
    return 0;
}