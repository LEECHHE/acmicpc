#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n1,n2; scanf("%d%d",&n1,&n2);
    if( n1 > n2 ) swap(n1,n2);
    int a = n2-n1+1;
    printf("%d",a*(a-1)/2);
    return 0;
}