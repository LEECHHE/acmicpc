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
long long tree[300000] = { 0 };

void update(long long idx, long long v){
    while(idx){
        tree[idx] += v;
        idx /= 2;
    }
}

long long sum(long long a, long long b){
    if( a>=b ) return a == b ? tree[a] : 0;
    
    if( a % 2 == 0 && b % 2 ) return sum(a/2,b/2);
    else if(a%2==0&&b%2==0) return sum(a/2,b/2-1)+tree[b];
    else if(a%2&&b%2) return sum(a/2+1,b/2)+tree[a];
    else return sum(a/2+1, b/2-1)+tree[a]+tree[b];
}
int main(){
    int n,q; scanf("%d%d",&n,&q);
    int idx = 1;
    while(idx<n) idx *= 2;
    for( int i = 0 ; i < n ; ++i ){
        int v; scanf("%d",&v);
        update(idx+i,v);
    }
    for( int i = 0 ; i < q ; ++i ){
        long long x,y,a,b; scanf("%lld%lld%lld%lld", &x,&y,&a,&b);
        if( x > y ) swap(x,y);
        printf("%lld\n", sum(idx+x-1,idx+y-1));
        update(idx+a-1, b-tree[idx+a-1]);
    }
    
    return 0;
}