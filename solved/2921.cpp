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
    int n; scanf("%d",&n);
    int ret = 0;
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 0 ; j <= i ; ++j ){
            ret += i+j;
//            printf("add %d + %d\n",i,j);
        }
    }
    printf("%d",ret);
    return 0;
}