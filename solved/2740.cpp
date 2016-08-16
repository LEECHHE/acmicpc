#include <cstdio>
using namespace std;
int a[100][100], b[100][100];
int ret[100][100];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            scanf("%d", &a[i][j]);
        }
    }
    int k; scanf("%d%d",&m,&k);
    for( int i = 0 ; i < m ; ++i ){
        for( int j = 0 ; j < k ; ++j ){
            scanf("%d",&b[i][j]);
        }
    }
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < k ; ++j ){
            for( int p = 0 ; p < m ; ++p ){
                ret[i][j] += a[i][p]*b[p][j];
            }
        }
    }

    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < k ; ++j ){
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}