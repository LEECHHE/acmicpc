#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,m; scanf("%d%d",&n,&m);
    int six = 2000, one = 2000;
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d", &a,&b);
        six = min(six,a);
        one = min(one,b);
    }
    int ret = 0;
    if( six <= one ){
        ret = n/6 * six;
        if(n%6) ret += six;
    }
    else{
        if( one*6 <= six ){
            ret = n * one;
        }
        else {
            ret = n/6*six;
            if( n%6*one > six ){
                ret += six;
            }
            else{
                ret += n%6*one;
            }
        }
    }
    printf("%d", ret);
    return 0;
}