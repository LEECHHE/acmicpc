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
char A[101]; char B[101]; char C[101];
int dp[105][105][105] = { 0 };
stack<char> ans;
int main(){
    scanf("%s%s%s",A,B,C);
    int idxA = (int)strlen(A);
    int idxB = (int)strlen(B);
    int idxC = (int)strlen(C);
    for ( int i = 1 ; i <= idxA ; ++i){
        for( int j = 1 ; j <= idxB;  ++j){
            for( int k = 1 ; k <= idxC; ++k ){
                if( A[i-1] == B[j-1] && B[j-1] == C[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max( max( dp[i-1][j][k], dp[i][j-1][k] ), dp[i][j][k-1]);
                }
            }
        }
    }
    printf("%d", dp[idxA][idxB][idxC]);
    return 0;
}