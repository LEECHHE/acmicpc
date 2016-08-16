#include <iostream>
#include <cstdio>
using namespace std;
bool isHan(int n){
    if( n == 1000 ) return false;
    if( n < 100 ) return true;
    int digit[3] = { n % 10, (n%100)/10 , n/100 };
    return (digit[0] - digit[1]) == (digit[1] - digit[2]);
}
int main(){
    int n; scanf("%d",&n);
    int ret = 0;
    for( int i = 1 ; i <= n ; ++i ){
        ret += isHan(i);
    }
    printf("%d", ret);
    return 0;
}