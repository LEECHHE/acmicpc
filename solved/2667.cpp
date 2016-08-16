#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#define INF 987654321
#define MAX_V 800
using namespace std;
char grid[25][26];
int n;
priority_queue<int, vector<int> , greater<int>> blocks;
void dfs(int x, int y, int& size);
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s", grid[i]);
    }
    for( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j < n ; ++j ){
            if( grid[i][j] == '1' ){
                int size = 0;
                dfs(i,j, size);
                blocks.push(size);
            }
        }
    }
    printf("%ld\n", blocks.size());
    while(!blocks.empty()){
        printf("%d\n", blocks.top());
        blocks.pop();
    }
    return 0;
}
void dfs( int x, int y, int& size){
    if( x < 0 || y < 0 || x >= n || y >= n ) return;
    if( grid[x][y] > '1') return;
    if( grid[x][y] == '0' ) return;
    
    grid[x][y] += blocks.size()+1;
    size++;
    dfs(x-1,y,size);
    dfs(x,y-1,size);
    dfs(x+1,y,size);
    dfs(x,y+1,size);
}