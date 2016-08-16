#include <cstdio>
using namespace std;
int main(){
    long long p[101] = { 0,1,1,1,2 };
    for( int i = 5 ; i <= 100 ; ++i ){
        p[i] = p[i-5]+p[i-1];
    }
    int n; scanf("%d",&n);
    while(n--){
        int t; scanf("%d",&t);
        printf("%lld\n",p[t]);
    }
    return 0;
}