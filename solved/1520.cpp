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
const int INF = (1<<31)-1;
int m,n;
int grid[505][505];
int ways[505][505] = { 0 };
void dfs(int x, int y, int* ret){
    if( x == m && y == n ){
        ++(*ret);
        return;
    }
    if( ways[x][y] >= 0 ){
        (*ret) += ways[x][y];
        return;
    }
    int cur = grid[x][y];
    int cnt = 0;
    if( cur > grid[x-1][y] ) dfs(x-1,y,&cnt);
    if( cur > grid[x+1][y] ) dfs(x+1,y,&cnt);
    if( cur > grid[x][y-1] ) dfs(x,y-1,&cnt);
    if( cur > grid[x][y+1] ) dfs(x,y+1,&cnt);
    ways[x][y] = cnt;
    (*ret) += cnt;
}
int main(){
    scanf("%d%d",&m,&n);
    for( int i = 0 ; i <= m ; ++i ) grid[i][0] = INF;
    for( int i = 0 ; i <= n ; ++i ) grid[0][i] = INF;
    for( int i = 1 ; i <= m ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            scanf("%d",&grid[i][j]);
            ways[i][j] = -1;
        }
    }
    int ret = 0;
    dfs(1,1,&ret);
    printf("%d", ways[1][1]);
    return 0;
}