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
int component[5][100] = { 0 };
int main(){
    int seq[5];
    for( int i = 0 ; i < 5 ; ++i ){
        int t; scanf("%d",&t);
        seq[i] = t;
        int d = 2;
        while(t > 1){
            while( (t % d) == 0 ){
                component[i][d]++;
                t /= d;
            }
            d++;
        }
    }
    long long ret = 10000000000L;
    for( int i = 0 ; i < 3 ; ++i ){
        for( int j = i+1; j < 4 ; ++j ){
            for( int k = j + 1 ; k < 5; ++k ){
                long long cur = 1;
                for( int d = 2 ; d < 100 ; ++d ){
                    cur *= (long long)pow(d, max(component[i][d], max(component[j][d], component[k][d])));
                }
                ret = min(ret, cur);
            }
        }
    }
    printf("%lld", ret);
    return 0;
}