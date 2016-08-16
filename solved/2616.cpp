#include<iostream>
#include<cstring>

using namespace std;
int seq[50001];
int dp[50001][3];
int psum[50001] = { 0 };
int n,k;
int solve(int idx, int t){
	if( t >= 3 ) return 0;
	if( idx > n ) return 0;
	int& ret = dp[idx][t];
	if( ret != -1 ) return ret;
	return ret = max(solve(idx+k,t+1)+psum[idx+k-1]-psum[idx-1],solve(idx+1,t));
}
int main(){
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) {
		scanf("%d",&seq[i]);
		psum[i] = psum[i-1]+seq[i];
	}
	scanf("%d",&k);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0,0));

	return 0;
}