#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int, int> intPair;
char board[15][15];
bool visited[15][15] = { false };
bool isRemoved = false;
vector<intPair> removed;
void dfs(int x, int y, char target, bool start){
    if( !visited[x-1][y] && board[x-1][y] == target ){
        visited[x-1][y] = true;
        removed.push_back(make_pair(x-1, y));
        dfs(x-1,y,target,false);
    }
    if( !visited[x+1][y] && board[x+1][y] == target ){
        visited[x+1][y] = true;
        removed.push_back(make_pair(x+1, y));
        dfs(x+1,y,target,false);
    }
    if( !visited[x][y-1] && board[x][y-1] == target ){
        visited[x][y-1] = true;
        removed.push_back(make_pair(x, y-1));
        dfs(x,y-1,target,false);

    }
    if( !visited[x][y+1] && board[x][y+1] == target ){
        visited[x][y+1] = true;
        removed.push_back(make_pair(x, y+1));
        dfs(x,y+1,target,false);
    }
    if( start ){
        if( removed.size() >= 4 ){
            isRemoved = true;
            for( auto p : removed ){
                board[p.first][p.second] = '.';
//                printf("(%d,%d) %c removed\n", p.first,p.second, target);
            }
        }
    }
}
int main(){
    for( int i = 1 ; i <= 12 ; ++i ){
        scanf("%s", board[i]+1);
    }
    int ret = 0;
    while(1){
        bool hasChanged = false;
        memset(visited, 0, sizeof(visited));
        for( int i = 12 ; i >= 1 ; --i ){
            for( int j = 1 ; j <= 6 ; ++j ){
                if(board[i][j] != '.' && !visited[i][j]){
                    removed.clear();
                    isRemoved = false;
                    char target = board[i][j];
                    visited[i][j] = true;
                    removed.push_back(make_pair(i, j));
                    dfs(i,j,target,true);
                    if( isRemoved ){
                        if(!hasChanged) ret++;
                        hasChanged = true;
                    }
                }
            }
        }
//        for( int i = 1 ; i <= 12 ; ++i ){
//            printf("%s\n", board[i]+1);
//        }
//        printf("\n");
        for( int i = 1; i<=6; ++i ){
            int floor = 12;
            for ( int j = 12 ; j >= 1 ; --j ){
                if( board[j][i] == '.'){
                    break;
                }
                --floor;
            }

            for( int j = floor ; j >= 1 ; --j ){
                if( board[j][i] != '.' ){
                    board[floor][i] = board[j][i];
                    board[j][i] = '.';
                    --floor;
                }
            }
//            printf("i = %d\n", i);
//            for( int i = 1 ; i <= 12 ; ++i ){
//                printf("%s\n", board[i]+1);
//            }
//            printf("\n");
        }
//        printf("Push down ends\n");
        if(!hasChanged) break;
    }
    printf("%d", ret);
    return 0;
}