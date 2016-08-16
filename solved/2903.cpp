#include <cstdio>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    int iter = 2;
    while(n--){
        iter = 2*iter-1;
    }
    printf("%d",iter*iter);
    return 0;
}