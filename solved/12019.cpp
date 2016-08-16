#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> intPair;
typedef long long ll;
int n,m;
ll dp[105][15][2005]; // i번째날 j번째 청소
int seq[105];
const ll INF = 1e18;
ll solve( int day, int cnt , int dirty){
    if( cnt > m ){
        return INF;
    }
    if ( day == n ){
        return dirty*seq[day];
    }
    ll& ret = dp[day][cnt][dirty];
    if( ret != -1 ) return ret;
    
    ll not_clear = solve(day+1,cnt,dirty+seq[day]);
    ll clear = solve(day+1,cnt+1,0);
    ret = dirty*seq[day]+min(not_clear,clear);
    return ret;
}
vector<int> cleaning;
void tracking( int day, int cnt , int dirty){
    if( day == n ) return;
    if( cleaning.size() == m ) return;
    if( dp[day+1][cnt][dirty+seq[day]] < dp[day+1][cnt+1][0] ){
        tracking(day+1,cnt,dirty+seq[day]);
    }
    else{
        cleaning.push_back(day);
        tracking(day+1, cnt+1, 0);
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&n,&m);
    seq[0] = 0;
    for( int i = 1 ; i <= n ; i += scanf("%d",&seq[i]));
    printf("%lld\n", solve(0,0,0));
    tracking(0, 0, 0);
    for( auto d : cleaning ){
        printf("%d ",d);
    }
    return 0;
}