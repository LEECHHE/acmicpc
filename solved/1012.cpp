#include <cstdio>
using namespace std;

void accessGrid(int x, int y, int count);
int m,n,k;
int grid[50][50];
int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&m,&n,&k);
        for( int i = 0 ; i < k ; ++i ){
            int x,y; scanf("%d%d",&x,&y);
            grid[y][x] = 1;
        }
        int ans = 0;
        for( int i = 0 ; i < n ; ++i ){
            for ( int j = 0 ; j < m ; ++j ){
                if( grid[i][j] == 1 ){
                    accessGrid(j, i, ++ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
void accessGrid(int x, int y, int count){
    if(x < 0 || y < 0 || x >= m || y >= n) return;
    if(grid[y][x] != 1) return;
    grid[y][x] = count+1;
    accessGrid(x-1, y, count);
    accessGrid(x, y-1, count);
    accessGrid(x+1, y, count);
    accessGrid(x, y+1, count);
}