#include <cstdio>
using namespace std;
int main(){
    int a,b; int n; scanf("%d%d%d",&a,&b,&n);
    a %= b;
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        ret = (a*10)/b;
        a = (a*10)%b;
    }
    printf("%d",ret);
    
    return 0;
}