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
typedef pair<int,int> intPair;
bool erased[1001] = { false };
int main(){
    int n,k; scanf("%d%d",&n,&k);
    int ret = 0;
    while(k){
        for( int idx = 2 ; ;++idx ){
            if(erased[idx]) continue;
            int mul = idx;
            while( idx <= n ){
                if( !erased[idx] ){
                    erased[idx] = true;
                    --k;
//                    printf("(%d,%d)\n", idx, k);
                    if( k == 0 ){
                        ret = idx;
                        break;
                    }
                }
                idx += mul;
            }
            break;
        }
    }
    printf("%d", ret);
    return 0;
}