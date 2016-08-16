#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
bool board[100][100] = { false };
const int dx[2] = {1,1};
const int dy[2] = {-1,1};
int id[2][100][100] = { 0 };
int n;
int cnt[2] = { 0 };
int t = 1;
vector<int> adj[10001];
int match[10001] = { 0 };
bool visitied[10001] = { false };
void makegraph(){
    for( int dir = 0 ; dir < 2 ; ++dir ){
        for( int x = 0 ; x < n ; ++x ){
            for( int y = 0 ; y < n ; ++y ){
                if( board[x][y] == false && id[dir][x][y] == 0 ){
                    int cx = x, cy = y;
                    while (0 <= cx && cx < n &&
                           0 <= cy && cy < n && board[cx][cy] == false
                           && id[dir][cx][cy] == 0) {
                        id[dir][cx][cy] = t;
                        cx += dx[dir];
                        cy += dy[dir];
                    }
                    cnt[dir]++;
                    ++t;
                }
            }
        }
    }
    for (int x = 0; x < n ; ++x) {
        for( int y = 0 ; y < n ; ++y ){
            if( board[x][y] ) continue;
            adj[id[0][x][y]].push_back(id[1][x][y]);
        }
    }
}
bool bpm(int v){
    for( auto next : adj[v]){
        if (visitied[next]) continue;
        visitied[next] = true;
        if( match[next] == -1 || bpm(match[next]) ){
            match[next] = v;
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d",&n);
    int m; scanf("%d",&m);
    for( int i = 0 ; i < m ; ++ i){
        int x,y; scanf("%d%d",&x,&y);
        board[x-1][y-1] = true;
    }
    makegraph();
    int ret = 0;
    memset(match, -1, sizeof(match));
    for( int i = 1 ; i <= cnt[0] ; ++i ){
        memset(visitied, 0, sizeof(visitied));
        if( bpm(i)) ++ret;
    }
    printf("%d",ret);
    return 0;
}