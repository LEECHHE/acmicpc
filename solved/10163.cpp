#include <cstdio>
using namespace std;
int covered[101][101] = {0 };
int main(){
    int n; scanf("%d",&n);
    int cnt[101] = { 0 };
    for( int i = 1 ; i <= n ; ++i ){
        int x1,y1,w,h; scanf("%d%d%d%d",&x1,&y1,&w,&h);
        cnt[i] = w*h;
        for( int x = x1 ; x < x1+w ; ++x ){
            for( int y = y1 ; y < y1+h ; ++y ){
                if( covered[x][y] != 0 ){
                    cnt[covered[x][y]]--;
                }
                covered[x][y]= i;
            }
        }
    }
    for( int i = 1 ; i <= n ; ++i ){
        printf("%d\n", cnt[i]);
    }
    return 0;
}