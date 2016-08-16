#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        ret += b % a;
    }
    printf("%d", ret);
    return 0;
}