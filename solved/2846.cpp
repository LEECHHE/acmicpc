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

int main(){
    int n; scanf("%d",&n);
    int seq[1000];
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d",&seq[i]);
    }
    int length = 1;
    int ret = 0;
    for( int i = 1 ; i < n ; ++i ){
        if( seq[i] > seq[i-1] ){
            ++length;
        }
        else{
            ret = max( ret, seq[i-1] - seq[i-length]) ;
            length = 1;
        }
    }
    if( length > 1 ) ret = max(ret, seq[n-1] - seq[n-length]);
    printf("%d", ret);
    return 0;
}