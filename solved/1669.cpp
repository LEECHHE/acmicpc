#include <cstdio>
using namespace std;
int main(){
    int a, b; scanf("%d%d", &a,&b);
    b -= a;
    int ans = 1;
    int height = 1;
    if( b == 0 ){
        ans = 0;
    }
    if( b - height <= 0 ){
        b -= height;
    }
    while(b > 0){
        ++ans;
        int sum = height * (height+1);
        if( ans % 2 == 0){
            if( b - sum <= 0 ){
                b -= sum;
            }
        }
        else{
            if( b - sum - ++height <= 0 ){
                b -= sum + height;
            }
        }
    }
    printf("%d", ans);
    return 0;
}