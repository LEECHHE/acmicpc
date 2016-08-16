#include <cstdio>
using namespace std;
int sum[2000001] = { 0 };

int main(){
    int n,s;scanf("%d%d",&n,&s);
    int seq[(1<<20)-1];
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        seq[1<<i] = t;
    }
    seq[0] = 0;
    int limit = 1 << n;
    for( int i = 1 ; i < limit ; ++i ){
        int p2 = 1;
        int cur = i;
        int subsum = 0;
        while(cur){
            subsum += seq[cur%2*p2];
            cur /= 2;
            p2 *= 2;
        }
        sum[subsum+1000000]++;
    }
    printf("%d",sum[s+1000000]);
    return 0;
}