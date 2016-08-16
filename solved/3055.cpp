#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> intPair;
const int dx[4] = { 0,0,1,-1};
const int dy[4] = { 1,-1,0,0};
char map[55][55];
int r,c;
bool isValid( int x, int y ){
    return 0 <= x && x < r && 0 <= y && y < c;
}
int main(){
    scanf("%d%d",&r,&c);
    
    int state[55][55] = { 0 };
    int x = -1,y = -1;
    for( int i = 0 ; i < r ; ++i ){
        scanf("%s", map[i]);
        for( int j = 0 ; j < c ; ++j ){
            if( map[i][j] == '*' ){
                state[i][j] = 2;
                continue;
            }
            else if( map[i][j] == 'X' ){
                state[i][j] = 3;
                continue;
            }
            if( map[i][j] == 'S' ){
                x = i, y = j;
            }
        }
    }

    state[x][y] = 1;
    queue<intPair> q;
    q.push(intPair(x,y));
    int ret = 0;
    bool hasArrived = false;
    while (!q.empty()) {
        for( int i = 0 ; i < r ; ++i ){
            for( int j = 0 ; j < c ; ++j ){
                if( map[i][j] == '*' ){
                    for( int k = 0 ; k < 4 ; ++k ){
                        if( isValid(i+dx[k], j+dy[k] ) && map[i+dx[k]][j+dy[k]] == '.' ){
                            map[i+dx[k]][j+dy[k]] = '+';
                        }
                    }
                }
            }
        }
        int len = q.size();
        ++ret;
        for( int k = 0 ; k < len ; ++k ){
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            
            if( state[xx][yy] == 2 ) continue;      //submerged
            for( int dir = 0 ; dir < 4 ; ++dir ){
                int _x = xx+dx[dir], _y = yy+dy[dir];
                if( !isValid(_x, _y) ) continue;
                if( state[_x][_y] >= 1 || map[_x][_y] =='+' ) continue;      //visited,submerged,blocked
                if( map[_x][_y] =='D'){
                    hasArrived = true;
                    break;
                }
                state[_x][_y] = 1;
                q.push(intPair(_x,_y));
            }
        }
        if( hasArrived ) break;
        
        
        for( int i = 0 ; i < r ; ++i ){
            for( int j = 0 ; j < c ; ++j ){
                if( map[i][j] =='+' ){
                    map[i][j] = '*';
                    state[i][j] = 2;
                }
            }
        }
    }
    if(!hasArrived) ret = -1;
    if( ret < 0 ) printf("KAKTUS");
    else printf("%d",ret);
    return 0;
}