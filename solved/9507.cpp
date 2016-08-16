#include <cstdio>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    long long koong[68] = { 1, 1, 2, 4 };
    for( int i = 4 ; i <= 67 ; ++i ){
        koong[i] = koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4];
    }
    while(t--){
        int k; scanf("%d",&k);
        printf("%lld\n",koong[k]);
    }
    return 0;
}