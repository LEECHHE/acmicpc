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
    int sum[11] = { 0 };
    int diff = 200;
    int ret = 0;
    for ( int i = 1 ; i <= 10 ; ++i ){
        int t; scanf("%d",&t);
        sum[i] = sum[i-1]+t;
    }
    
    for( int i = 1 ; i <= 10 ; ++i ){
        int current = sum[i];
        int curDiff = abs(100-current);
        if( diff > curDiff){
            ret = current;
            diff = curDiff;
        }
        else if( diff == curDiff ){
            ret = max(ret,current);
        }
    }
    printf("%d", ret);
    return 0;
}