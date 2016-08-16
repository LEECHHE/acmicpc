#include <cstdio>
using namespace std;
bool rect[101][101];
int main(){
    for( int i = 0 ; i < 4 ; ++i ){
        int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for( int i = x1 ; i < x2 ; ++i ){
            for( int j = y1 ; j < y2 ; ++j ){
                rect[i][j] = true;
            }
        }
    }
    int ret = 0;
    for( int i = 0 ; i <= 100 ; ++i ){
        for( int j = 0 ; j <= 100 ; ++j ){
            if( rect[i][j] ) ++ret;
        }
    }
    printf("%d",ret);
    return 0;
}