#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int arr[1000];
        int dp[1001] = { 0 };
        
        scanf("%d", &arr[0]);
        dp[1] = arr[0];
        
        for( int i = 1 ; i < n ; ++i ){
            scanf("%d", &arr[i]);
            dp[i+1] += dp[i] + arr[i];
        }
        int max = -987654321;
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 0 ; j < i ; ++j ){
                if( dp[i] - dp[j] > max ){
                    max = dp[i] - dp[j];
                }
            }
        }
        printf("%d\n", max);
    }
    
    return 0;
}