#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    char s[2][4001]; scanf("%s%s",s[0],s[1]);
    int ret = 0;
    int len[2] = { (int)strlen(s[0]), (int)strlen(s[1]) };
    for( int i = 0 ; i < len[0] ; ++i ){
        int cnt = 0;
        for( int j = 0 ; j < len[1] ; ++j ){
            if( i+j < len[0] && s[0][i+j] == s[1][j] ) ++cnt;
            else{
                ret = max(cnt,ret);
                cnt = 0;
            }
        }
        ret = max(cnt,ret);
    }
    for ( int i = 0 ; i < len[1] ; ++i ){
        int cnt = 0;
        for( int j = 0 ; j < len[0] ; ++j ){
            if( i+j < len[1] && s[1][i+j] == s[0][j] ) ++cnt;
            else{
                ret = max(cnt,ret);
                cnt = 0;
            }
        }
        ret = max(cnt,ret);
    }
    printf("%d",ret);
    return 0;
}