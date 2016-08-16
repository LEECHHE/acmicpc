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
    int n;
    int factorial[10000] = { 1,1};
    for( int i = 2 ; i < 10000 ; ++i ){
        factorial[i] = factorial[i-1]*i;
        while(factorial[i]%10 == 0){
            factorial[i] /= 10;
        }
        factorial[i] %= 100000;
    }
    while(scanf("%d",&n) != -1){
        printf("%5d -> %d\n", n,factorial[n]%10);
    }
    return 0;
}