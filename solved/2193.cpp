#include <cstdio>
using namespace std;

int main(){
    int N;
    unsigned long long cache[90][2];   //cache[N][0,1]
    
    scanf("%d", &N);
    
    //base:
    cache[0][0] = 0;
    cache[0][1] = 1;
    for( int i = 1 ; i < N ; i++ ){
        cache[i][0] = cache[i-1][0] + cache[i-1][1];
        cache[i][1] = cache[i-1][0];
    }
    
    printf("%llu", cache[N-1][0] + cache[N-1][1]);
    
    return 0;
}