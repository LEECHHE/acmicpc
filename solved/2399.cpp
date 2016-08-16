#include <cstdio>
using namespace std;
int main(){
    int seq[10000];
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&seq[i]);
    }
    long long ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        for (int j = 0 ; j < n ; ++j ) {
            int cur = seq[i]-seq[j];
            if( cur < 0 ) cur *= -1;
            ret += cur;
        }
    }
    printf("%lld",ret);
    return 0;
}