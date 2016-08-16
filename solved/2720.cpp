#include<cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
#define Q 25
#define D 10
#define N 5
    while(n--){
        int money; scanf("%d", &money);
        printf("%d ",money/Q); money %= Q;
        printf("%d ",money/D); money %= D;
        printf("%d %d\n",money/N,money%N);
    }
    return 0;
}