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
int mintree[300000];
int maxtree[300000] = { 0 };
void update(int idx, int v){
    while(idx){
        mintree[idx] = min(v, mintree[idx]);
        maxtree[idx] = max(v, maxtree[idx]);
        idx /= 2;
    }
}
int getMax(int a, int b){
    if(a>=b){
        return a == b ? maxtree[a] : max(maxtree[(a-1)*2+1], maxtree[(b+1)*2]);
    }
    if( a % 2 == 0 && b % 2 ) return getMax(a/2,b/2);
    else if( a % 2 == 0 && b % 2 == 0 ) return max(getMax(a/2, b/2-1), maxtree[b]);
    else if( a % 2 && b % 2 ) return max(getMax(a/2+1, b/2), maxtree[a]);
    else return max(getMax(a/2+1, b/2-1),max(maxtree[a],maxtree[b]));
}
int getMin(int a, int b){
    if(a>=b){
        return a == b ? mintree[a] : min(mintree[(a-1)*2+1], mintree[(b+1)*2]);
    }
    if( a % 2 == 0 && b % 2 ) return getMin(a/2,b/2);
    else if( a % 2 == 0 && b % 2 == 0 ) return min(getMin(a/2, b/2-1), mintree[b]);
    else if( a % 2 && b % 2 ) return min(getMin(a/2+1, b/2), mintree[a]);
    else return min(getMin(a/2+1, b/2-1),min(mintree[a],mintree[b]));
}
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int idx = 1;
    while( idx< n) idx *= 2;
    int max_int = (1<<31)-1;
    for( int i = 0 ; i < 300000 ; ++i ){
        mintree[i] = max_int;
    }
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d", &t);
        update(idx+i,t);
    }
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        printf("%d %d\n", getMin(idx+a-1,idx+b-1), getMax(idx+a-1,idx+b-1));
    }
    return 0;
}