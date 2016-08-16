#include <cstdio>
#include <cstring>
using namespace std;
int dp[2001][2001];
int seq[2001];
bool solve(int s, int e){
    if( s >= e ) return 1;
    int& ret = dp[s][e];
    if(ret != -1) return ret;
    return ret = solve(s+1, e-1) && seq[s] == seq[e];
}
int main(){
    int n; scanf("%d",&n);
    memset(dp, -1, sizeof(dp));
    for( int i = 1 ; i <= n ; i += scanf("%d",&seq[i]));
    int m; scanf("%d",&m);
    while (m--) {
        int s,e; scanf("%d%d",&s,&e);
        printf("%d\n",solve(s, e));
    }
    return 0;
}