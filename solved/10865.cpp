#include <cstdio>
using namespace std;

int main(){
    int n,m; scanf("%d%d",&n,&m);
    int fr[100000] = { 0 };
    for(int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d", &a,&b);
        fr[a-1]++;
        fr[b-1]++;
    }
    for(int i = 0 ; i < n ; ++i ){
        printf("%d\n", fr[i]);
    }
    return 0;
}