#include <cstdio>
using namespace std;
int main(){
    bool numbers[2000001] = { false };
    int N; scanf("%d", &N);
    while(N--){
        int t; scanf("%d", &t);
        numbers[t+1000000] = true;
    }
    for( int i = 0 ; i <= 2000000; ++i)
        if( numbers[i] ) printf("%d\n", i-1000000);
    return 0;
}