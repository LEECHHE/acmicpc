#include <cstdio>
#include <cstring>
using namespace std;
char board[30][30];
char line[] = "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#";
int main(){
    int m,n; scanf("%d%d",&m,&n);
    int u,l,r,d; scanf("%d%d%d%d",&u,&l,&r,&d);
    for( int i = 0 ; i < m+u+d ; ++i ){
        memcpy(board[i], line+i%2, sizeof(char)*(n+l+r));
        board[i][n+l+r] = '\0';
    }
    for( int i = u ; i < m+u ; ++i ){
        char k[30]; scanf("%s", k);
        memcpy(board[i]+l, k, sizeof(char)*n);
    }
    for( int i = 0 ; i < m+u+d ; ++i ){
        printf("%s\n", board[i]);
    }
    return 0;
}