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
int child[200];
int n; int dp[205];
const int NEGINF = -10000;
int lis(int idx){
    int& ret = dp[idx+1];
    if( ret != 0 ) return ret;
    
    int currentMax = idx == -1 ? NEGINF : child[idx];
    ret = 1;
    for ( int next = idx+1 ; next < n ; ++next ){
        if( child[next] > currentMax ){
            ret = max( lis(next) + 1 , ret );
//            printf("child[%d] - %d : %d\n", idx+1, child[idx+1] , ret);
        }
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; ++i ) {
        scanf("%d",&child[i]);
        dp[i] = 0;
    }
    printf("%d",n-lis(-1)+1);
    return 0;
}