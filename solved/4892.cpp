#include <cstdio>
#include <algorithm>
using namespace std;
void solve(int k, int n){
    switch (k) {
        case 0:
            solve(1, 3*n);
            break;
        case 1:
            n%2 ? printf("odd ") : printf("even ");
            solve(2, (n+n%2)/2);
            break;
        case 2:
            solve(3, 3*n);
            break;
        case 3:
            solve(4, n/9);
            break;
        case 4:
            printf("%d\n",n);
            break;
    }
}
int main(){
    for (int i=1; ; ++i) {
        int n; scanf("%d",&n);
        if (n==0) break;
        printf("%d. ",i);
        solve(0, n);
    }
    return 0;
}