#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
bool adj[2050][2050];
vector<int> aMatch, bMatch;
bool visited[2050];
bool dfs(int v){
    if( visited[v] ) return false;
    visited[v] = true;
    for( int b = 0 ; b < m ; ++b ){
        if( adj[v][b] ){
            if(bMatch[b] == -1 || dfs(bMatch[b])){
                aMatch[v] = b;
                bMatch[b] = v;
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for( int i = 0 ; i < n ; ++i ){
        int k; scanf("%d",&k);
        for( int j = 0 ; j < k ; ++j ){
            int p; scanf("%d",&p);
            adj[i][p-1] = 1;
        }
    }
    aMatch = vector<int>(n,-1), bMatch = vector<int>(m,-1);
    int ret = 0;
    for( int start = 0 ; start < n ; ++start ){
        memset(visited, 0, sizeof(visited));
        if(dfs(start)){
            ++ret;
        }
    }
    printf("%d",ret);
    return 0;
}