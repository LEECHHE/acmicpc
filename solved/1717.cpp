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
int parent[1000001];
int rk[1000001];
int find(int u){
    if( parent[u] == u ) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if( u == v ) return;
    
    if( rk[u] < rk[v] )
        swap(u,v);
    
    parent[v] = u;
    
    if( rk[u] == rk[v] ) ++rk[u];
}
int main(){
    int n, m; scanf("%d%d",&n,&m);
    for( int i = 0 ; i <= n ; ++i ){
        parent[i] = i;
        rk[i] = 1;
    }
    
    for( int i = 0 ; i < m ; ++i ){
        int op, a, b; scanf("%d%d%d", &op, &a, &b);
        if( op == 0 ){
            merge(a, b);
        }
        else{
            if(find(a) == find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}