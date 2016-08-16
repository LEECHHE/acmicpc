#include<cstdio>
#include<algorithm>
using namespace std;
int seq[1000001];
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; i += scanf("%d",&seq[i]));
    int ret = -1;
    sort(seq, seq+n);
    for( int i = n-3 ; i >= 0 ; --i ){
        int l = seq[i]+seq[i+1];
        if( l > seq[i+2] ){
            ret = l + seq[i+2];
            break;
        }
    }
    printf("%d", ret);
    return 0;
}