#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int grid[101][101] = { 0 };
int m,n,k;

void dfs(int& s, int x, int y);
int main(){
    scanf("%d%d%d",&m,&n,&k);
    while(k--){
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for( int i = x1; i < x2; ++i ){
            for ( int j = y1 ; j < y2; ++j )
                ++grid[i][j];
        }
    }
    vector<int> square;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            int count = 0;
            if( grid[i][j] == 0 )
                dfs(count, i, j);
            if( count > 0 )
                square.push_back(count);
        }
    }
    sort(square.begin(), square.end());
    printf("%d\n", (int)square.size());
    for( auto s : square ) printf("%d ", s);
    return 0;
}
void dfs(int& s, int x, int y){
    if( x < 0 || y < 0 || x >= n || y >= m ) return;
    if( grid[x][y] != 0 ) return;    // already visited or occupied
    
    ++s; grid[x][y] = -1;
    dfs(s, x-1,y);
    dfs(s, x,y-1);
    dfs(s, x+1,y);
    dfs(s, x,y+1);
}