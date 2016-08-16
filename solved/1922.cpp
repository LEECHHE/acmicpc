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
typedef pair<int,int> intPair;
const int INF = (1<<31)-1;
int v,e;
int parent[10001];
int cnt[10001];
int rnk[10001];
int find(int a){
    if( parent[a] == a ) return a;
    return parent[a] = find(parent[a]);
}
void merge(int v, int w){
    v = find(v); w = find(w);
    if( v == w ) return;
    
    if( rnk[v] < rnk[w] ) swap(v,w);
    parent[w] = v;
    if( rnk[v] == rnk[w] ) ++rnk[v];
    cnt[v] += cnt[w];
}


int main(){
    scanf("%d%d",&v,&e);
    for( int i = 0 ; i <= v ; ++i ){
        parent[i] = i;
        cnt[i] = 1;
        rnk[i] = 1;
    }
    priority_queue< pair<int, intPair>, vector<pair<int, intPair> >, greater<pair<int, intPair>> >  pq;
    int ret = 0;
    for( int i = 0 ; i < e ; ++i ){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        pq.push(make_pair(c, make_pair(a, b)));
    }

    while(1){
        pair<int, intPair> cur = pq.top();
        pq.pop();
        int fir = cur.second.first;
        int sec = cur.second.second;
        if( find(fir) != find(sec) ){
            merge(fir,sec);
            ret += cur.first;
            if( cnt[find(fir)] == v ) break;
        }
    }
    printf("%d",ret);
    
    return 0;
}