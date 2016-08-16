#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int color[20001] = { 0 };
vector<int> adj[20001];
string ret = "YES";
void dfs(int node, int col){
    color[node] = col;
    for( auto next : adj[node] ){
        if( color[next] == 0 ){
            dfs(next, -col);
            if( ret[0] == 'N' ) break;
        }
        else if( color[next] == col){
            ret = "NO";
            return;
        }
    }
}
int main(){
    int k; scanf("%d",&k);
    while (k--) {
        int v,e; scanf("%d%d",&v,&e);

        memset(color, 0, sizeof(color));
        for( int i = 1 ; i <= v ; ++i ) adj[i].clear();
        for( int i = 0; i < e ; ++i ){
            int a,b; scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if( v == 1 ){
            printf("NO");
            continue;
        }
        ret = "YES";
        for( int i = 1; i <= v ; ++i ){
            if( color[i] == 0 ){
                dfs(i, 1);
                if( ret[0] == 'N')
                    break;
            }
        }
        printf("%s\n", ret.c_str());
    }
    return 0;
}