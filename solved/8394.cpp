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
    int a = 1,b = 2,c = -1;
    int n; scanf("%d",&n);
    if( n == 1 ) printf("1");
    else if( n == 2) printf("2");
    else{
        for( int i = 3 ; i <= n ; ++i ){
            c = (a + b) % 10;
            a = b % 10;
            b = c % 10;
        }
        printf("%d",c);
    }
    return 0;
}