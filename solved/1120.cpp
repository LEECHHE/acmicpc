#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
char seq[2][51];
int main(){
    scanf("%s%s", seq[0], seq[1]);
    int la = (int)strlen(seq[0]);
    int lb = (int)strlen(seq[1]);
    int ret = 100;
    for( int i = 0 ; i <= lb-la ; ++i ){
        int dist = 0;
        for( int j = i ; j < i+la ; ++j ){
            if( seq[0][j-i] != seq[1][j] ){
                ++dist;
            }
        }
        ret = min(ret, dist);
    }
    printf("%d",ret);
    return 0;
}