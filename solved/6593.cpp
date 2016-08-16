#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
const int dx[6] = { 0,0,1,-1,0,0};
const int dy[6] = { 1,-1,0,0,0,0};
const int dz[6] = { 0,0,0,0,1,-1};
typedef pair<int, int> intPair;
typedef pair<intPair,int> pos;
bool visited[35][35][35] = { false };
char building[35][35][35];
int l,r,c;
bool isValid(int x, int y, int z){
    return 0<= x && x < l && 0 <= y && y < r && 0 <= z && z < c;
}
int main(){
    while (1) {
        scanf("%d%d%d",&l,&r,&c);
        if( l == 0 && r == 0 && c == 0 ) break;
        memset(visited, 0, sizeof(visited));
        pos s = pos(intPair(-1,-1),-1);
        for( int i = 0 ; i < l ; ++i ){
            for( int j = 0 ; j < r ; ++j ){
                scanf("%s",building[i][j]);
                if( s.second < 0 ){
                    for( int k = 0 ; k < c ; ++k ){
                        if( building[i][j][k] =='S'){
                            s = pos(intPair(i,j),k);
                            break;
                        }
                    }
                }
            }
        }
        
        queue<pos> q;
        visited[s.first.first][s.first.second][s.second] = true;
        int ret = -1;
        int turn = 0;
        q.push(s);
        while (!q.empty()) {
           ++turn;
            int len = q.size();
            for( int i = 0 ; i < len ; ++i ){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int z = q.front().second;
                q.pop();
                
                for( int d = 0 ; d < 6 ; ++d ){
                    int cx = x+dx[d];
                    int cy = y+dy[d];
                    int cz = z+dz[d];
                    if( !isValid(cx, cy, cz) || visited[cx][cy][cz] ) continue;
                    if( building[cx][cy][cz] == '#' ) continue;
                    if ( building[cx][cy][cz] == 'E' ){
                        ret = turn;
                        break;
                    }
                    visited[cx][cy][cz] = true;
                    q.push(pos(intPair(cx,cy),cz));
                }
                if( ret > 0 ) break;
            }
            if( ret > 0 ) break;
        }
        if( ret < 0 ){
            printf("Trapped!\n");
        }
        else{
            printf("Escaped in %d minute(s).\n",ret);
        }
    }
    return 0;
}