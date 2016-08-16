#include <cstdio>
#include <cstring>
using namespace std;
const int row = 1;
const int col = 2;
char tochar(char c){
    if(c == 0 ) return '.';
    else if( c == 1 ) return '-';
    else if (c == 2 ) return '|';
    else return '+';
}
int main(){
    char board[101][101] = { 0 };
    char op[1001];
    int n; scanf("%d%s",&n,op);
    for( int i = 0 ; i < n ; ++i ){
        board[i][n] = '\0';
    }
    int len = (int)strlen(op);
    int x = 0;
    int y = 0;
    for( int i = 0 ; i < len ; ++i ){
        if( op[i] == 'U'){
            if( x == 0 ) continue;
            board[x][y] |= col;
            board[--x][y] |= col;
        }
        else if(op[i] == 'D'){
            if( x == n-1 ) continue;
            board[x][y] |= col;
            board[++x][y] |= col;
        }
        else if(op[i] == 'L'){
            if( y == 0 ) continue;
            board[x][y] |= row;
            board[x][--y] |= row;
        }
        else if(op[i] == 'R'){
            if( y == n-1 ) continue;
            board[x][y] |= row;
            board[x][++y] |= row;
        }
    }
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            board[i][j] = tochar(board[i][j]);
        }
        printf("%s\n", board[i]);
    }
    return 0;
}