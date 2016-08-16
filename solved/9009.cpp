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
vector<int> fib;
int main(){
    fib.push_back(0);
    fib.push_back(1);
    
    for( long long cur = 1; ;){
        fib.push_back((int)cur);
        cur += fib[fib.size()-2];
        if( cur > 1000000000 ) break;
    }
    int n; scanf("%d",&n);
    while(n--){
        int target; scanf("%d",&target);
        vector<int> ans;
        while(target){
            int idx = (int)(lower_bound(fib.begin(), fib.end(), target) - fib.begin());
            if( fib[idx] != target ) idx--;
            target -= fib[idx];
//            printf("target: %d, fib: %d\n", target, fib[idx]);
//            getchar();
            ans.push_back(fib[idx]);
        }
        reverse(ans.begin(), ans.end());
        for ( auto i : ans ){
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}