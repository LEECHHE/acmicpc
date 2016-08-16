#include <cstdio>
#include <algorithm>
using namespace std;
int seq[2000000];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int len = n+m;
    for( int i = 0 ; i < len ; ++i ){
        scanf("%d",&seq[i]);
    }
    sort(seq, seq+len);
    for( int i = 0 ; i < len ; ++i ){
        printf("%d ",seq[i]);
    }
    return 0;
}