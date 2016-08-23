#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
int dp[300001];
vector<int> bullets;
int min(int a, int b){ return a < b ? a : b; }
ll sum(ll k){
	return k*(k+1)*(k+2)/6;
}
int n;
const int INF = 300001;
int solve(ll k){
	if( k == 0 ) return 0;
	int& ret = dp[k];
	if( ret != -1 ) return ret;
    ret = INF;
	for( auto bullet : bullets){
        int remain = k-bullet;
        if( remain < 0 ) break;
		ret = min(ret,solve(remain)+1);
	}
	return ret;
}
int main(){
	for( int i = 1 ; ; ++i ){
		int k = sum(i);
		if( k > 300000 ) break;
		bullets.push_back(k);
	}
	scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
	printf("%d",solve(n));
	return 0;
}