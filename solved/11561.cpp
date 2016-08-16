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
long long sum(long long n){
    return n*(n+1)/2;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        long long n; scanf("%lld",&n);
        long long lastStep = (1 << 31)-1;
        long long left = 1, right = lastStep;
        while(1){
            long long pivot = (left+right)/2;
            long long cur = sum(pivot);
//            printf("pivot : %lld, cur : %lld\n", pivot, cur);
            if( cur > n ){
                right = pivot;
            }
            else{
                if( cur + pivot >= n ){
                    lastStep = pivot;
                    break;
                }
                left = pivot;
            }
        }
        printf("%lld\n", lastStep);
    }
    return 0;
}