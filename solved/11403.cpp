#include <cstdio>
using namespace std;
int adj[100][100];
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            scanf("%d",&adj[i][j]);
        }
    }
    for (int k = 0; k < n ; ++k ) {
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                adj[i][j] |= adj[i][k] && adj[k][j];
            }
        }
    }
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}