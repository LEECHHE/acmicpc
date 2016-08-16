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
int p10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d", &n);
        int len = 0;
        while(p10[len]<=n) len++;
//        printf("len: %d\n", idx);
        for( int idx = 1 ; idx <= len; ++idx ){
            if( n > p10[idx] ){
                n += p10[idx]/2;
                n /= p10[idx];
                n *= p10[idx];
            }
        }
        printf("%d\n",n);
    }
    return 0;
}