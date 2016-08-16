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
    int cake[1001] = { 0 };
    int l, n; scanf("%d%d", &l,&n);
    
    int expected_idx = 0;
    int expected_amount = -1;
    int real_idx = 1;
    int real_amount = -1;
    for( int i = 1 ; i <= n ; ++i ){
        int a,b; scanf("%d%d", &a,&b);
        if( expected_amount < b-a+1) {
            expected_amount = b-a+1;
            expected_idx = i;
        }
        int cnt = 0;
        for( int j = a ; j <= b ; ++j ){
            if( cake[j] == 0 ){
                ++cnt;
                cake[j] = i;
            }
        }
        if( real_amount < cnt ){
            real_amount = cnt;
            real_idx = i;
        }
    }
    printf("%d\n%d", expected_idx, real_idx);
    return 0;
}