#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
const int dx[2] = { 0, 1 };
const int dy[2] = { 1, 0 };
char board[101][101];
int id[2][101][101] = { 0 };
int t = 1;
int cnt[2] = { 0 };
vector<int> adj[10000];
void makegraph(int n){
    for( int dir = 0 ; dir < 2 ; ++dir ){
        for( int x = 0 ; x < n ; ++x ){
            for( int y = 0 ; y < n ; ++y ){
                if( board[x][y] == '.' && id[dir][x][y] == 0){
                    int cx = x, cy = y;
                    while (0<= cx && cx < n &&
                           0 <= cy && cy < n && board[cx][cy] =='.' &&
                           id[dir][cx][cy] == 0) {
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
    for( int x = 0 ; x < n ; ++x ){
        for( int y = 0 ; y < n ; ++y ){
            if( board[x][y]=='.' )
                adj[id[0][x][y]].push_back(id[1][x][y]);
        }
    }
}
bool visited[20001] = { false };
int match[20001];
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
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s", board[i]);
    }
    makegraph(n);
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