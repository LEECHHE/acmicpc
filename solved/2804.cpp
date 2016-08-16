#include <cstdio>
#include <cstring>
using namespace std;
char board[35][35];
int main(){
    int idxa = 31, idxb = 31;
    char a[35], b[35]; scanf("%s%s",a,b);
    int lena = (int)strlen(a), lenb = (int)strlen(b);
    for( int i = 0 ; i < lena ; ++i ){
        for( int j = 0 ; j < lenb ; ++j ){
            board[j][i] = '.';
        }
    }
    for( int i = 0 ; i < lena ; ++i ){
        for( int j = 0 ; j < lenb ; ++j ){
            if( a[i] == b[j] ){
                if( idxa > i ){
                    idxa = i;
                    idxb = j;
                }
                break;
            }
        }
    }
    for( int i = 0 ; i < lena ; ++i ){
        board[idxb][i] = a[i];
    }
    for( int i = 0 ; i < lenb ; ++i ){
        board[i][idxa] = b[i];
        board[i][lena] = '\0';
        printf("%s\n", board[i]);
    }
    return 0;
}