#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int adj[100][100] = { 0 };
bool visited[100] = { false };
int match[100];
bool bpm( int v ){
    if( visited[v] ) return false;
    visited[v] = true;
    for( int b = 0 ; b < m ; ++b ){
        if( !adj[v][b] ) continue;
        if( match[b] == -1 || bpm(match[b])){
            match[b] = v;
            return true;
        }
    }
    return false;
}
double p2(double x){
    return x*x;
}
int main(){
    int s,v;
    scanf("%d%d%d%d",&n,&m,&s,&v);
    double r = p2(s*v);
    double rat[100][2];
    for( int i = 0 ; i < n ; ++i ){
        scanf("%lf%lf",&rat[i][0],&rat[i][1]);
    }
    for( int i = 0 ; i < m ; ++i ){
        double x,y; scanf("%lf%lf",&x,&y);
        for( int j = 0 ; j < n ; ++j ){
            if (p2(rat[j][0]-x)+p2(rat[j][1]-y) <= r+0.0000000001) {
                adj[j][i] = 1;
            }
        }
    }
    int ret = 0;
    memset(match, -1, sizeof(match));
    for( int start = 0 ; start < n ; ++start ){
        memset(visited, 0, sizeof(visited));
        if( bpm(start) ) ++ret;
    }
    printf("%d", n-ret);
    return 0;
}