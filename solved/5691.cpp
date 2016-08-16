#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    while(1){
        int ret = (1<<31)-1;
        int a, b; scanf("%d %d", &a,&b);
        if( a == 0 && b == 0 ) break;
        
        ret = min(2*b-a,min(2*a-b, ret));
        if( (a+b) % 2 == 0 ) ret = min(ret, (a+b)/2);
        printf("%d\n", ret);
    }
}