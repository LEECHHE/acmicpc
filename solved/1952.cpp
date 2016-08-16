#include <cstdio>
using namespace std;

int main(){
    int m,n; scanf("%d%d",&m,&n);
    bool visited[101][101] = { false };
    for (int i = 0; i < m; ++i) {
        visited[i][n] = true;
    }
    for (int i = 0; i < n ; ++i) {
        visited[m][i] = true;
    }
    visited[0][0] = true;
    int x = 0, y = 0;
    int direction = 0;
    int ret = 0;
    int cnt = 1;
    while (cnt < n*m) {
        if( direction == 0 ){
            for( ; y < n ; ++y ){
                if( visited[x][y+1] ){
                    ++ret;
                    direction = 1;
                    break;
                }
                visited[x][y] = true;
                ++cnt;
            }
        }
        else if( direction == 1 ){
            for( ; x < m ; ++x ){
                if( visited[x+1][y] ){
                    ++ret;
                    direction = 2;
                    break;
                }
                visited[x][y] = true;
                ++cnt;
            }
        }
        else if( direction == 2 ){
            for (; y >= 0; --y) {
                if( y == 0 || visited[x][y-1] ){
                    ++ret;
                    direction = 3;
                    break;
                }
                visited[x][y] = true;
                ++cnt;
            }
        }
        else{
            for (; x>=0; --x) {
                if(visited[x-1][y]){
                    ++ret;
                    direction = 0;
                    break;
                }
                visited[x][y] = true;
                ++cnt;
            }
        }
    }
    printf("%d",ret-1);
    return 0;
}