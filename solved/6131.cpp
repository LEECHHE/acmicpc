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
bool exist[250001] = { false };
int main(){
    int n; scanf("%d",&n);
    int ret = 0 ;
    for( int i = 1 ; i <= 500 ; ++i ){
        int cur = i*i;
        exist[cur] = true;
        if( cur - n >= 1 )
            ret += exist[cur-n];
    }
    printf("%d",ret);
    return 0;
}