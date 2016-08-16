#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int d = 2;
    while(n>1){
        while(n%d==0){
            printf("%d\n",d);
            n /= d;
        }
        ++d;
    }
    return 0;
}