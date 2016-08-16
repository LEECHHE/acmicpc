#include <cstdio>
#include <algorithm>
using namespace std;
const int limit = 25;
int fib[limit] = { 1,1};
int main(){
    for( int i = 2 ; i < limit ; ++i ){
        fib[i] = fib[i-1]+fib[i-2];
    }
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<int> mile;
        while (n>0) {
            int idx = (int)(lower_bound(fib, fib+limit, n)-fib);
            if( fib[idx] != n ) --idx;
            n -= fib[idx];
            mile.push_back(idx-1);
        }
        int ret = 0;
        for (auto m : mile ){
            if( m >= limit ) continue;
            ret += fib[m];
        }
        printf("%d\n",ret);
    }
    return 0;
}