#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    char seq[51]; scanf("%s",seq);
    int ret = 1;
    bool isL = false;
    for( int i = 0 ; i < n ; ++i ){
        if( seq[i] == 'L' ){
            if( isL ){
                ++ret;
                isL = 0;
            }
            else{
                isL = 1;
            }
        }
        else{
            ++ret;
        }
    }
    printf("%d", min(ret,n));
    return 0;
}