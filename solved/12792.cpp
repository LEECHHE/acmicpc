#include<cstdio>
using namespace std;
int seq[1000001];
int main(){
    int n; scanf("%d",&n);
    int ret = 1000003;
    for( int i = 1 ; i <= n ; ++i ){
        scanf("%d",&seq[i]);
        if( ret > 0 && seq[i] == i ) ret = -1;
    }
    printf("%d", ret);
    return 0;
}