#include <cstdio>
using namespace std;
int main(){
    int term[100001] = { 0 };
    int n; scanf("%d",&n);
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        term[t]++;
    }
    int ret = -1;
    for (int i = 0 ; i <= 100000 ; ++i ){
        if( term[i] == i ) ret = i;
    }
    printf("%d",ret);
    return 0;
}