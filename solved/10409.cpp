#include <cstdio>
using namespace std;

int main(){
    int n,T; scanf("%d%d",&n,&T);
    int result = 0;
    while( n-- ){
        int num; scanf("%d",&num);
        T -= num;
        if ( T < 0 ) break;
        result++;
    }
    printf("%d",result);
    return 0;
}