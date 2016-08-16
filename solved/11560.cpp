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
    int t; scanf("%d",&t);
    while(t--){
        long long coef[211] = { 0 };
        int k,n; scanf("%d%d",&k,&n);
        coef[0] = coef[1] = 1;
        for( int i = 2 ; i <= k ; ++i ){
            long long before[211]; memcpy(before, coef, sizeof(coef));
            memset(coef, 0, sizeof(coef));
            int len = (i-1)*i/2;
            for( int p = 0 ; p <= i ; ++p ){
                for( int q = 0; q <= len ; ++q ){
                    coef[p+q] += before[q];
//                    printf("add %d to %d\n", p+q, before[q]);
                }
            }
        }
        printf("%lld\n", coef[n]);
    }
    return 0;
}