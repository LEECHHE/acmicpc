#include <cstdio>
using namespace std;
int seq[100001] = {0 };
int main(){
    int n; scanf("%d",&n);
    scanf("%d",&seq[1]);
    for(int i = 2 ; i <= n ; ++i ){
        scanf("%d",&seq[i]);
        seq[i] += seq[i-1];
    }
    int m; scanf("%d",&m);
    while(m--){
        int a,b; scanf("%d%d",&a,&b);
        printf("%d\n",seq[b]-seq[a-1]);
    }
    return 0;
}