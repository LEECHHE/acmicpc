#include <cstdio>
using namespace std;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int p[101][101] = { 0 };
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for( int x = x1 ; x <= x2 ; ++x ){
            for( int y = y1 ; y <= y2 ; ++y ){
                p[x][y]++;
                if( p[x][y] == m+1 ) ++ret;
            }
        }
    }
    printf("%d",ret);
    return 0;
}