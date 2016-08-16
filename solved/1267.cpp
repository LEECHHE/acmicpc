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
    int n; scanf("%d", &n);
    int sum[2] = { 0 };
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        int m = 1;
        int y = 1;
        for( ; t - y * 30 >= 0 ; ++y );
        for( ; t - m * 60 >= 0 ; ++m );
        sum[0] += 10 * y;

        sum[1] += 15 * m;
     //   printf("y - %d\nm - %d\n", 10*y, 15*m);
    }
    if ( sum[0] < sum[1] ){
        printf("Y %d", sum[0]);
    }
    else if( sum[0] == sum[1] ){
        printf("Y M %d", sum[0]);
    }
    else
        printf("M %d", sum[1]);
    return 0;
}