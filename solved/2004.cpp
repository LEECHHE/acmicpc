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
    vector<long long> p5;
    vector<long long> p2;
    p2.push_back(2);
    p5.push_back(5);
    while( p2.back() <= 2000000000){
        p2.push_back(p2.back()<<1);
    }
    p2.push_back(p2.back()<<1);
    while( p5.back() <= 2000000000 ){
        p5.push_back(p5.back()*5);
    }
    p5.push_back(p5.back()*5);
    long long n,m; scanf("%lld%lld",&n,&m);
    long long factor[] = { n, m, n-m};
    long long cnt[3][2] = { 0 };
    for( int i = 0 ; i < 3 ; ++i ){
        for(int idx = 0; factor[i] >= p2[idx] ; ++idx )
            cnt[i][0] += factor[i]/p2[idx];
        for(int idx = 0; factor[i] >= p5[idx] ; ++idx )
            cnt[i][1] += factor[i]/p5[idx];
    }
    cnt[0][0] -= cnt[1][0]+cnt[2][0]; cnt[0][1] -= cnt[1][1]+cnt[2][1];
    
    printf("%lld", min(cnt[0][0],cnt[0][1]));
    return 0;
}