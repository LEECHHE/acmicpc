#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int ret = 0;
    for( int i = 0 ; i < 5 ; ++i ){
        int t; scanf("%d",&t);
        ret += t == n;
    }
    printf("%d", ret);
    return 0;
}