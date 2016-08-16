#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    long long ret = 0;
    long long pow10 = 10;
    int cnt = 1;
    for( int i = 0 ; i < 11 ; ++i ){
        if( n / pow10 > 0 ){
            ret += (cnt % 1234567) * ((pow10 - pow10/10) % 1234567);
            ret %= 1234567;
            pow10 *= 10;
            cnt++;
        }
        else{
            pow10 /= 10;
//            n %= pow10;
            ret += (cnt % 1234567) * ((n-pow10+1)%1234567);
            ret %= 1234567;
            break;
        }
    }
    printf("%lld\n", ret);
    return 0;
}