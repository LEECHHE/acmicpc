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
int b[3] = {300,60,10};
int main(){
    int t; scanf("%d",&t);
    int ans[3] = { -1,-1,-1 };
    for ( int a = t/300 ; a >= 0 ; --a ){
        for( int b = (t-300*a)/60 ; b >= 0 ; --b ){
            int remain = t - 300*a - 60 * b;
            if( remain % 10 == 0 ){
                ans[0] = a;
                ans[1] = b;
                ans[2] = remain/10;
                break;
            }
        }
        if( ans[0] >= 0 ) break;
    }
    if( ans[0] < 0 ) printf("-1");
    else printf("%d %d %d", ans[0], ans[1],ans[2]);
    return 0;
}