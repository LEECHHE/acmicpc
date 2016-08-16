#include<cstdio>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    for ( int i = 0 ; i < n ; ++i ){
        long long a, b; scanf("%lld%lld",&a,&b);
        printf("Scenario #%d:\n",i+1);
        printf("%lld\n\n",(a+b)*(b-a+1)/2);
    }
    return 0;
}