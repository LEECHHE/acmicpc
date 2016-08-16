#include <cstdio>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int grid[100][100];
        int n,m; scanf("%d%d",&n,&m);
        for( int i =0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
                scanf("%d", &grid[i][j]);
            }
        }
        int ret = 0;
        for( int j = 0 ; j < m ; ++j ){
            int bottom = n;
            int cur = n-1;
            while (cur >= 0) {
                if( grid[cur][j] == 1 ){
                    ret += bottom-cur-1;
                    --bottom;
                }
                --cur;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}