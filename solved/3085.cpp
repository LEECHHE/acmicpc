#include <cstdio>
#include <algorithm>
using namespace std;
char board[50][51];
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { 1, -1, 0, 0 };
int n;
int ret = 0;
bool isValid(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}
int process( int x, int y){
    char cur = board[x][y];
    int row = 0, col = 0;
    for( int cx = x ; isValid(cx,y) && board[cx][y] == cur ; --cx){
        ++col;
    }
    for( int cx = x+1 ; isValid(cx,y) && board[cx][y] == cur ; ++cx){
        ++col;
    }
    for( int cy = y ; isValid(x,cy) && board[x][cy] == cur ; --cy){
        ++row;
    }
    for( int cy = y+1 ; isValid(x,cy) && board[x][cy] == cur ; ++cy){
        ++row;
    }
    return max(row,col);
}
int check(int x, int y){
    int ret = process(x, y);
    for (int dir = 0; dir < 4 ; ++dir) {
        int cx = x+dx[dir], cy = y+dy[dir];
        if( !isValid(cx, cy)) continue;
        swap(board[cx][cy], board[x][y]);
        ret = max(ret, process(cx,cy));
        swap(board[cx][cy], board[x][y]);
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%s", board[i]);
    }
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            ret = max(ret, check(i,j));
        }
    }
    printf("%d",ret);
    return 0;
}