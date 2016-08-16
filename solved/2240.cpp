#include <iostream>
#include <cstring>
using namespace std;
int max( int a , int b ) { return a > b ? a : b; }
int t,w;
int dp[1005][31][2];
int seq[1005];
int solve(int clk, int step, int pos){
	if( step > w ) return -1;
	if( clk == t ) return seq[t]==pos;
	int& ret = dp[clk][step][pos-1];
	if( ret != -1 ) return ret;
	
	return ret = (seq[clk]==pos)+max(solve(clk+1,step,pos),solve(clk+1,step+1,pos==1?2:1));
}
int main(){
	scanf("%d%d",&t,&w);
	for( int i = 1 ; i <= t ; ++i ){
		scanf("%d",&seq[i]);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(0,0,1));
	return 0;
}