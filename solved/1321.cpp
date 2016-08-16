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
int tree[1500000];
const int MAX = 1500000;

void update(int idx, int v){
    while(idx){
        tree[idx] += v;
        idx /= 2;
    }
}

int find(int k){
    int idx = 1;
    int currentCnt = k;
    while(currentCnt){
        if( idx*2+1 >= MAX ||
           (tree[idx*2] == 0 && tree[idx*2+1] == 0) ){
            break;
        }
        if( currentCnt <= tree[idx*2] ){
            idx *= 2;
        }
        else{
            currentCnt -= tree[idx*2];
            idx = idx*2+1;
        }
    }
    return idx;
}
int main(){
    int idx = 1;
    int n; scanf("%d",&n);
    while(idx<n) idx *= 2;
    for( int i = 0 ; i < n ; ++i ){
        int v; scanf("%d",&v);
        update(idx+i, v);
    }
    int m; scanf("%d",&m);
    for ( int i = 0 ; i < m ; ++i ){
        int op; scanf("%d", &op);
        if ( op == 1 ){
            int k,v; scanf("%d%d", &k,&v);
            update(idx+k-1,v);
        }
        else {
            int k; scanf("%d", &k);
            printf("%d\n",find(k)-idx+1);
        }
    }
    return 0;
}