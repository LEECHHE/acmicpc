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
vector<pair<int, int>> a;
int dp[105] = { 0 };
int n;
const int NEGINF = -100000;
int lis(int idx){
    int& ret = dp[idx+1];
    if( ret != 0 ) return ret;
    
    int currentMax = idx == -1 ? NEGINF : a[idx].second;
    ret = 1;
    for( int next = idx+1 ; next < n ; ++next ){
        if( currentMax < a[next].second )
            ret = max( ret, lis(next)+1);
    }
    return ret;
}
int main(){
    scanf("%d",&n);

    for( int i = 0 ; i < n ; ++i ){
        int p,q; scanf("%d%d",&p,&q);
        a.push_back(make_pair(p, q));
    }
    sort(a.begin(), a.end());
    
    int inc = n-lis(-1)+1;
    printf("%d", inc);
    return 0;
}