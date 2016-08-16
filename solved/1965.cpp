#include<cstdio>
#include<stack>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int n;
int boxes[1001] = { 0 };
int dp[1001] = { 0 };

int GetDP(int i, int j){
	if (i < 0 || j < 0) return 0;
	if (i >= n || j >= n) return 0;

	return dp[i];
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &boxes[i]);
		dp[i] = 1;
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (boxes[i] > boxes[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans = max(ans, dp[i]);
	}

	printf("%d", ans);
	return 0;
}