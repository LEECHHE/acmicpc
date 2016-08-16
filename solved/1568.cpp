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
    long long n; scanf("%lld", &n);
    int ret = 0;
    int current = 1;
    while(n > 0){
        n -= current++;
        if( current > n ) current = 1;
        ++ret;
    }
    printf("%d", ret);
    return 0;
}