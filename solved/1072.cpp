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
typedef long long lli;
int main(){
    lli n, m;
    while(scanf("%lld%lld", &n, &m) != -1){
        lli z = m * 100 / n;
        if( z >= 99 ){
            printf("-1\n");
            continue;
        }
        lli target = ceil(((double)n * (1+z) - 100 * m) / (99-z));
        printf("%lld\n", target);
    }
    return 0;
}