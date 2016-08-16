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
char A[1001]; char B[1001];
int dp[1005][1005] = { 0 };
stack<char> ans;
int main(){
    scanf("%s%s",A,B);
    int idxA = (int)strlen(A);
    int idxB = (int)strlen(B);
    for ( int i = 1 ; i <= idxA ; ++i){
        for( int j = 1 ; j <= idxB;  ++j){
            if( A[i-1] == B[j-1] ){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
    }
    int ret = dp[idxA][idxB];
    while( ans.size() < ret ){
        int current = dp[idxA][idxB];
        while( current == dp[idxA-1][idxB] ){
            idxA--;
        }
        while( current == dp[idxA][idxB-1]){
            idxB--;
        }
        if( current > dp[idxA-1][idxB-1]){
            ans.push(B[idxB-1]);
            idxA--;
            idxB--;
        }
    }
    printf("%d\n", ret);
    while(!ans.empty()){
        printf("%c",ans.top());
        ans.pop();
    }
    return 0;
}