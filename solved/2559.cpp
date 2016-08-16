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
int t[100005];
int sum[100005] = { 0 };
int main(){
    int n,k; scanf("%d%d",&n,&k);
    scanf("%d", &t[1]);
    sum[1] = t[1];
    int ret = k > 1 ? 1<<31 : t[1];
    for( int i = 2 ; i <= n ; ++i ){
        scanf("%d", &t[i]);
        sum[i] = sum[i-1]+t[i];
        if( i >= k ){
            ret = max( ret, sum[i] - sum[i-k] );
        }
    }
    printf("%d", ret);
    return 0;
}