#include<cstdio>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> intPair;
const int INF = (1<<31)-1;
char cell[55][55];
int n,m;
int bfs(int x, int y){
    int dist[50][50];
    for( int i=0; i<n;++i){
        for( int j = 0 ; j < m ; ++j ){
            dist[i][j] = INF;
        }
    }
    queue<intPair> q;
    q.push(make_pair(x, y));
    dist[x][y] = 0;
    int ret = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int d = dist[x][y];
        ret = max(ret,d);
        q.pop();
        
        if( x > 0 && cell[x-1][y] =='L' && dist[x-1][y] > d+1){
            dist[x-1][y] = d+1;
            q.push(make_pair(x-1, y));
        }
        if( x < n-1 && cell[x+1][y] =='L' &&dist[x+1][y] > d+1){
            dist[x+1][y] = d+1;
            q.push(make_pair(x+1, y));
        }
        if( y > 0 && cell[x][y-1] =='L' && dist[x][y-1] > d+1){
            dist[x][y-1] = d+1;
            q.push(make_pair(x, y-1));
        }
        if( y < m-1 && cell[x][y+1] =='L' &&dist[x][y+1] > d+1){
            dist[x][y+1] = d+1;
            q.push(make_pair(x, y+1));
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s", cell[i]);
    }
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ;j < m ; ++j ){
            if( cell[i][j] == 'L')
                ret = max(ret, bfs(i,j));
        }
    }
    printf("%d", ret);
    return 0;
}