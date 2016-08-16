#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
const int dx[2] = { 0, 1 };
const int dy[2] = { 1, 0 };
bool blank[301][301];
int id[2][301][301] = { 0 };
int t = 1;
int cnt[2] = { 0 };
vector<int> adj[301];
void makegraph(int r, int c){
    for( int dir = 0 ; dir < 2 ; ++dir ){
        for( int x = 1 ; x <= r ; ++x ){
            for( int y = 1 ; y <= c ; ++y ){
                if( blank[x][y] ) continue;
                if( id[dir][x][y] == 0 ){
                    int cx = x, cy = y;
                    while (1<= cx && cx <= r &&
                           1 <= cy && cy <= c &&
                           id[dir][cx][cy] == 0) {
                        if( !blank[cx][cy] )
                            id[dir][cx][cy] = t;
                        cx += dx[dir];
                        cy += dy[dir];
                    }
                    ++cnt[dir];
                    ++t;
                }
            }
        }
    }
    for( int x = 1 ; x <= r ; ++x ){
        for( int y = 1 ; y <= c ; ++y ){
            if( blank[x][y] ) continue;
            adj[id[0][x][y]].push_back(id[1][x][y]);
        }
    }
}
bool visited[601] = { false };
int match[601];
bool bpm(int v){
    for( auto next : adj[v] ){
        if(visited[next]) continue;
        visited[next] = true;
        if( match[next] == -1 || bpm(match[next])){
            match[next] = v;
            return true;
        }
    }
    return false;
}
int main(){
    int r,c,n; scanf("%d%d%d",&r,&c,&n);
    for( int i = 0 ; i < n ; ++i ){
        int x,y; scanf("%d%d",&x,&y);
        blank[x][y] = true;
    }
    makegraph(r, c);
    memset(match, -1, sizeof(match));
    int ret = 0;
    for( int start = 1 ; start <= cnt[0] ; ++start ){
        memset(visited, 0, sizeof(visited));
        if( bpm(start) ){
            ++ret;
        }
    }
    printf("%d",ret);
    return 0;
}