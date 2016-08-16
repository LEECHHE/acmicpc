#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    if( a < b ) swap(a, b);
    while (b) {
        int t = a%b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        int seq[100];
        for( int i = 0 ; i < n ; ++i ) scanf("%d",&seq[i]);
        int ret = 0;
        for( int i = 0 ; i < n-1 ; ++i ){
            for( int j = i+1 ; j < n ; ++j ){
                ret += gcd(seq[i], seq[j]);
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}