#include <cstdio>
using namespace std;
int main(){
    int a,b; scanf("%d",&a);
    char op[2];
    while(1){
        scanf("%s", op);
        if( op[0] == '=' ) break;
        scanf("%d", &b);
        if( op[0] == '+' )
            a += b;
        else if(op[0] == '-')
            a -= b;
        else if(op[0] == '*')
            a *= b;
        else if(op[0] == '/')
            a /= b;
    }
    printf("%d",a);
    return 0;
}