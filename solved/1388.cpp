#include<cstdio>
using namespace std;

int main(){
    int n,m; scanf("%d%d",&n,&m);
    char board[101][101];
    for( int i = 0 ; i < n ; ++i ) scanf("%s", board[i]);
    int ret = 0;
    for (int i = 0; i < n ; ++i ) {
        for( int j = 0 ; j < m ; ++j ){
            if( board[i][j] == '.' ) continue;
            if (board[i][j] == '-') {
                int y = j;
                while (board[i][y] == '-' && y < m ) {
                    board[i][y++] = '.';
                }
                ++ret;
            }
            else if( board[i][j] =='|'){
                int x = i;
                while (board[x][j] == '|' && x < n) {
                    board[x++][j] = '.';
                }
                ++ret;
            }
        }
    }
    printf("%d", ret);
    return 0;
}