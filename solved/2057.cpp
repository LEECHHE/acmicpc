#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
    ll factorial[20] = { 1, 1 };
    for( ll i = 2 ; i <= 19 ; ++i ){
        factorial[i] = factorial[i-1]*i;
    }
    bool used[20] = { false };
    ll n; scanf("%lld", &n);
    if( n == 0 ){
        printf("NO");
        return 0;
    }
    string ret = "YES";
    while(n){
        int idx = 19;
        while (factorial[idx] > n) {
            --idx;
        }
        if( used[idx] ){
            if( idx >= 3){
                ret = "NO";
                break;
            }
            else{
                while (used[idx]) {
                    --idx;
                }
            }
        }
        if( idx < 0 ){
            ret = "NO";
            break;
        }
        n -= factorial[idx];
        used[idx] = true;
    }
    printf("%s", ret.c_str());
    return 0;
}