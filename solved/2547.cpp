#include <cstdio>
using namespace std;
typedef unsigned long long ull;
ull total = 0;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        total = 0;
        ull n; scanf("%lld",&n);
        for( int i = 0 ; i < n ; ++i ){
            ull candy; scanf("%lld", &candy);
            total += candy % n;
            total %= n;
        }
        if( total == 0 ){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}