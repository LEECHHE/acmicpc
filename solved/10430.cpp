#include<cstdio>
using namespace std;
int main(){
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    int ans1 = (a+b)%c;
    int ans2 = (a*b)%c;
    printf("%d\n%d\n%d\n%d",ans1,ans1,ans2,ans2);
    return 0;
}