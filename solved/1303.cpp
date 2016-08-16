#include <cstdio>
using namespace std;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
char grid[105][105];
int n,m;
int search(int x, int y, char c){
    int ret = 1;
    grid[x][y] = '.';
    for( int d = 0 ; d < 4 ; ++d ){
        int cx = x+dx[d], cy = y+dy[d];
        if(!(0 <= cx && cx < m && 0 <= cy && cy < n )) continue;
        if( grid[cx][cy] == c ){
            ret += search(cx,cy,c);
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for( int i = 0 ; i < m ; i += scanf("%s", grid[i]));
    int w = 0, b = 0;
    for( int i = 0 ; i < m ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            if( grid[i][j] == 'W' ){
                int k = search(i,j,'W');
                w += k*k;
            }
            if( grid[i][j] =='B'){
                int k = search(i,j,'B');
                b += k*k;
            }
        }
    }
    printf("%d %d",w,b);
    return 0;
}