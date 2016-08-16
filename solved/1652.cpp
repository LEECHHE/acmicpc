#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    char room[105][105];
    for( int i = 0 ; i < n ; ++i ) scanf("%s", room[i]);
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            if( room[i][j] == 'X' ) continue;
            int cnt = 0;
            while(j < n && room[i][j] =='.'){
                ++cnt;
                ++j;
            }
            if( cnt >= 2 ) ++ret;
        }
    }
    printf("%d ", ret);
    ret = 0;
    for( int j = 0 ; j < n ; ++j ){
        for( int i = 0 ; i < n ; ++i ){
            if( room[i][j] == 'X' ) continue;
            int cnt = 0;
            while(i < n && room[i][j] =='.'){
                ++cnt;
                ++i;
            }
            if( cnt >= 2 ) ++ret;
        }
    }
    printf("%d", ret);
    return 0;
}