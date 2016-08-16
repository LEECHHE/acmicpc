#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
//0: 없음. 1: 왼. 2: 오
int dp[3][100000] = { 0 };
int main(){
    int n; scanf("%d",&n);
    for( int i = 0 ; i < 3 ; ++i ) dp[i][0] = 1;
    for( int i = 1 ; i < n ; ++i ){
        dp[0][i] = (dp[1][i-1] + dp[2][i-1] + dp[0][i-1]) % 9901;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % 9901;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1]) % 9901;
    }
    int ret = 0;
    for( int i = 0 ; i < 3 ; ++i ) ret += dp[i][n-1];
    printf("%d", ret % 9901);
    return 0;
}