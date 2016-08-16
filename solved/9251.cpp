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
int main(){
    scanf("%s%s",A,B);
    int lA = (int)strlen(A);
    int lB = (int)strlen(B);
    for ( int i = 1 ; i <= lA ; ++i){
        for( int j = 1 ; j <= lB;  ++j){
            if( A[i-1] == B[j-1] ){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
    }
    
    printf("%d", dp[lA][lB]);
    return 0;
}