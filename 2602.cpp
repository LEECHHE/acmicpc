#include<iostream>
#include<cstring>

using namespace std;
int dp[25][105][2];
char stones[2][105];
char paper[25];
int n,m;
int solve(int p, int idx, bool angel){
	if ( p >= n ) return 1;
	if ( idx >= m ) return 0;
	int& ret = dp[p][idx][angel];
	if( ret != -1 ) return ret;
	char target = paper[p];
	ret = solve(p, idx+1, angel);
	if( stones[angel][idx] == target ){
		ret += solve(p+1,idx+1,(angel+1)%2);
	}
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%s",paper);
	n = strlen(paper);
	scanf("%s%s",stones[0],stones[1]);
	m = strlen(stones[0]);
	int ret = solve(0,0,true)+solve(0,0,false);
	printf("%d",ret);
	return 0;
}

