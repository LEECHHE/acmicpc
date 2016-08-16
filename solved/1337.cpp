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
int seq[10000];
int n;
int need(int current,int idx){
    int expected[5];
    for( int i = 0 ; i < 5 ; ++i ){
        expected[i] = i-idx;
    }
    int ret = 4;
    for( int i = 0 ; i < 5 ; ++i ){
        if( expected[i] == 0 ) continue;
        ret -= *lower_bound(seq, seq+n, seq[current]-expected[i]) == seq[current]-expected[i];
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&seq[i]);
    }
    sort(seq, seq+n);
    int ret = 10;
    for( int i = 0 ; i < n ; ++i ){
        for( int idx = 0 ; idx < 5 ; ++idx ){
            ret = min(ret, need(i, idx));
        }
    }
    printf("%d", ret);
    return 0;
}