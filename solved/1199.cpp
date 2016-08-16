#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> route;
int n, adj[1000][1000];
int degree[1000] = { 0 };

bool isPossible(){
    for( int i = 0 ; i < n ; ++i ){
        if( degree[i] % 2 ) return false;
    }
    return true;
}
void dfs(int idx){
    for( int i = 0 ; i < n ; ++i ){
        if(adj[idx][i]){
            adj[idx][i]--;
            if(i != idx)
                adj[i][idx]--;
            dfs(i);
        }
    }
    route.push_back(idx+1);
}
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            scanf("%d", &adj[i][j]);
            if( adj[i][j] && i != j){
                degree[i] += adj[i][j];
            }
        }
    }
    if(!isPossible()) printf("-1");
    else{
        dfs(0);
    }
    for( int i = route.size()-1 ; i >= 0 ; --i ){
        printf("%d ",route[i]);
    }
    return 0;
}