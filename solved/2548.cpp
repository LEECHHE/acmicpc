#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int seq[20001]; int sum[20001];
    for( int i = 1; i <= n ; ++i ){
        scanf("%d",&seq[i]);
    }
    sort(seq+1, seq+n+1);
    for (int i= 1 ; i <= n ; ++i) {
        sum[i] = sum[i-1]+seq[i];
    }
    int mini = (1<<31)-1;
    int ret = 0;
    for( int i = 1 ; i <= n ; ++i ){
        if (seq[i] == seq[i-1]) continue;
        int val = seq[i]*i-sum[i]+(sum[n]-sum[i])-seq[i]*(n-i);
        if( mini > val ){
            mini = val;
            ret = seq[i];
        }
    }
    printf("%d",ret);
    return 0;
}