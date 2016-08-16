#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> list;
int dp[1000][1001];
int n,m;
int p2(int k){
    return k*k;
}
const int INF = 987654321;
int solve(int idx, int length){
    if( idx >= list.size() ) return 0;
    if( length > m ) return INF;
    int& ret = dp[idx][length];
    if( ret != -1 ) return ret;
    return ret = min(p2(m-length)+solve(idx+1,list[idx+1]),solve(idx+1,length+1+list[idx+1]));
}
int main(){
    cin >> n >> m;
    list = vector<int>(n);
    for( int i = 0 ; i < n ; ++i ) cin >> list[i];
    memset(dp,-1,sizeof(dp));
    cout << solve(0,list[0]);
    return 0;
}