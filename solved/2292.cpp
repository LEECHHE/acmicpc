#include <cstdio>
using namespace std;
int firstTerm(int n){
    return 3*n*(n-1)+2;
}
int main(){
    int n; scanf("%d",&n);
    int group = 1;
    while(firstTerm(group++)<=n);

    printf("%d", group-1);
    return 0;
}