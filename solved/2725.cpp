#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a, int b){
    while(b){
        int t = a%b;
        a = b;
        b = t;
    }
    return a;
}
int cnt[1001] = { 0 };
int main(){
    int t; scanf("%d",&t);
    for( int i = 2; i <= 1000 ; ++i ){
        for( int j = i-1 ; j >= 1 ; --j ){
            cnt[i] += (gcd(i, j) == 1);
        }
    }
    while(t--){
        int ret = 0;
        int n; scanf("%d",&n);
        for( int i = 2 ; i <= n ; ++i ){
            ret += cnt[i];
        }
        ret *= 2;
        ret += 3;
        printf("%d\n", ret);
    }
    return 0;
}