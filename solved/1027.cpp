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
long long building[50] = { 0 };
bool isBlocked(long long current, long long target, long long j){
    if(current == target) return false;
    if(current == j) return true;
    
    if( target < current ){
        return (building[current]-building[target]) * (current-j) >= (building[current]-building[j]) * (current - target);
    }
    else {
        return (building[target]-building[current]) * (j-current) <= (building[j]-building[current]) * (target-current);
    }
}
int main(){
    int n; scanf("%d",&n);
    for ( int i = 0 ; i < n ; ++i){
        scanf("%lld",&building[i]);
    }
    // (i, building[i]) - (j, building[j]) : (b[j] - b[i])/j-i * (x-i) + b[i]
    long long ans = -1;
    for( long long current = 0 ; current < n; ++current){
        long long count = 0;
        if( current > 0 ){
            for( long long target = current-1 ; target >= 0; --target ){
                bool canViewed = true;
                for( long long between = target+1 ; between < current ; ++ between ){
                    if( isBlocked(current, target, between)){
                        canViewed = false;
                        break;
                    }
                }
                if( canViewed ) ++count;
            }
        }
        if( current < n-1 ){
            for( long long target = current+1 ; target < n; ++target ){
                bool canViewed = true;
                for( long long between = target-1 ; between > current ; -- between ){
                    if( isBlocked(current, target, between)){
                        canViewed = false;
                        break;
                    }
                }
                if( canViewed ) ++count;
            }
        }
        if( count > ans ) ans = count;
    }
    printf("%lld", ans);
    
    return 0;
}