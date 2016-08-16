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
typedef pair<int,int> IntPair;
int n,grid[105][105] = { 0 };
int findSecure(){
    int ret = 0;
    int visited[105][105];
    queue<pair<int, int>> que;
    memcpy(visited, grid, sizeof(grid));
    for( int i = 1 ; i<= n ; ++i ){
        for( int j = 1 ; j <=n ; ++j ){
            if( visited[i][j] > 0){
                ++ret;
                que.push(make_pair(i, j));
                visited[i][j] = 0;
                while(!que.empty()){
                    IntPair current = que.front();
                    que.pop();
                    
                    if( visited[current.first-1][current.second] > 0 ){
                        visited[current.first-1][current.second] = 0;
                        que.push(make_pair(current.first-1, current.second));
                    }
                    if( visited[current.first][current.second-1] > 0){
                        visited[current.first][current.second-1] = 0;
                        que.push(make_pair(current.first, current.second-1));
                    }
                    if( visited[current.first+1][current.second] > 0){
                        visited[current.first+1][current.second] = 0;
                        que.push(make_pair(current.first+1, current.second));
                    }
                    if( visited[current.first][current.second+1] > 0){
                        visited[current.first][current.second+1] = 0;
                        que.push(make_pair(current.first, current.second+1));
                    }
                }
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    int ret = 1;
    int minimum = 200;
    int maximum = -1;
    for( int i = 1 ; i<= n ; ++i ){
        for( int j = 1 ; j <=n ; ++j ){
            scanf("%d",&grid[i][j]);
            minimum = min(minimum, grid[i][j]);
            maximum = max(maximum, grid[i][j]);
        }
    }
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            grid[i][j] -= minimum;
        }
    }
    maximum -= minimum;
    for( int rain = 0 ; rain <= maximum ; ++rain ){
        if( rain > 0 ){
            for( int i = 1 ; i <= n ; ++i ){
                for( int j = 1 ; j <= n ; ++j ){
                    grid[i][j] -= 1;
                }
            }
        }
        ret = max( ret, findSecure() );
    }
    printf("%d", ret);
    return 0;
}