#include <cstdio>
using namespace std;

int main(){
    long long n,k; scanf("%lld%lld",&n,&k);
    long long ret = 0;
    if( n == 1 ){
        ret = 8*k;
    }
    else if(n < 5){
        ret = 8*(k/2)+n-1;
        if( k % 2 ) ret += 2*(4-n)+2;
    }
    else{
        ret = 8*k+4;
    }
    printf("%lld",ret);
    return 0;
}