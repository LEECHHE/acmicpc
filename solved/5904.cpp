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
    vector<long long> L;
    L.push_back(0);
    L.push_back(3);
    long long cur = 3;
    for( int n = 1 ; ;++n){
        cur = 2*cur+n+3;
        L.push_back(cur);
        if( cur >= 1000000000 ) break;
    }
    int n; scanf("%d",&n);
//    int idx = (int)(lower_bound(L.begin(), L.end(), n)-L.begin());
    char ret = 'x';
    while(1){
        int idx = (int)(lower_bound(L.begin(), L.end(), n)-L.begin());
        if( n > L[idx]-L[idx-1] ){
            n -= L[idx-1] + idx+2;
        }
        else if( n > L[idx-1] ){
            n -= L[idx-1];
            if( n == 1 ) ret = 'm';
            else ret = 'o';
            break;
        }
    }
    printf("%c", ret);
    return 0;
}