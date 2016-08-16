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
long long tree[3000000];
void maketree(){
    
}
void update(int idx, long long k){
    while(idx){
        tree[idx] += k;
        idx /= 2;
    }
}

long long sum(long long a, long long b){
    if( a >= b ){
        return a == b ? tree[a] : 0;
    }
    if( a % 2 == 0 && b % 2 ){
        return sum(a/2, b/2);
    }
    else if( a%2 == 0 && b % 2 == 0 ){
        return sum(a/2, b/2-1) + tree[b];
    }
    else if( a%2 && b%2==0 ){
        return sum(a/2+1, b/2-1) + tree[a]+tree[b];
    }
    else if( a%2 && b%2 ){
        return sum(a/2+1, b/2) + tree[a];
    }
    return 0;
}
int main(){
    int n, m, k; scanf("%d%d%d", &n,&m,&k);
    int idx = 1;
    while(idx<n){
        idx *= 2;
    }
    for( int i = idx ; i < idx+n ; ++i ){
        long long t; scanf("%lld", &t);
        update(i, t);
    }
    for( int i = 0 ; i < m+k ; ++i ){
        int op,a; long long b; scanf("%d%d%lld",&op,&a,&b);
        if( op == 1 ){
            int target = idx + a - 1;
            update(target, b-tree[target]);
        }
        else {
            printf("%lld\n", sum(idx+a-1,idx+b-1));
        }
    }
    
    return 0;
}