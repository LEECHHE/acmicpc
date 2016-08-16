#include <cstdio>
using namespace std;
int grid[2200][2200];
int cnt[3] = { 0 };
int decompose(int size, int x, int y){
    if( size == 1 ) return grid[x][y];
    int downSize = size/3;
    int paper[3][3] = {
        { decompose(downSize, x, y), decompose(downSize, x, y+downSize), decompose(downSize, x, y+downSize*2)},
        { decompose(downSize, x+downSize, y), decompose(downSize, x+downSize, y+downSize), decompose(downSize, x+downSize, y+downSize*2)},
        { decompose(downSize, x+2*downSize, y), decompose(downSize, x+2*downSize, y+downSize), decompose(downSize, x+2*downSize, y+downSize*2)}
    };
    if( paper[0][0] == paper[0][1] && paper[0][1] == paper[0][2] && paper[0][2] == paper[1][0] &&
       paper[1][0] == paper[1][1] && paper[1][1] == paper[1][2] && paper[1][2] == paper[2][0] &&
       paper[2][0] == paper[2][1] && paper[2][1] == paper[2][2]
       && paper[0][0] != -2){
        return paper[0][0];
    }
    else{
        for( int i = 0 ; i < 3 ; ++i ){
            for( int j = 0 ; j < 3 ; ++j ){
                if(paper[i][j] == -2) continue;
                cnt[paper[i][j]+1]++;
            }
        }
        return -2;
    }
}
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        for ( int j = 0 ; j < n ; ++j )
            scanf("%d",&grid[i][j]);
    }
    if( n > 1 )
        decompose(n, 0, 0);
    else
        cnt[grid[0][0]+1]++;
    printf("%d\n%d\n%d",cnt[0],cnt[1],cnt[2]);
    return 0;
}