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
    int k,n; scanf("%d%d",&k,&n);
    vector<int> primes(k);
    vector<int> primePointer(k,0);
    vector<int> ans;
    for( int i = 0 ; i < k ; ++i ) scanf("%d",&primes[i]);
    ans.push_back(1);
    while(ans.size()<n+1){
        int _min = (1<<31)-1;
        int* idx = &primePointer[0];
        for( int i = 0 ; i < k ; ++i ){
            int cur = primes[i] * ans[primePointer[i]];
            if( cur < _min ){
                _min = cur;
                idx = &primePointer[i];
            }
        }
        (*idx)++;
        if( _min > ans.back() ){
            ans.push_back(_min);
//            printf("%d is pushed. idx : %d\n", _min, *idx);
        }
    }
    printf("%d", ans.back());
    return 0;
}