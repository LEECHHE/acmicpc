#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int c; scanf("%d",&c);
    while(c--){
        int seq[20], n; scanf("%d",&n);
        for( int i = 0 ; i < n ; ++i ){
            scanf("%d",&seq[i]);
        }
        sort(seq, seq+n);
        printf("%d\n", (seq[n-1]-seq[0])*2);
    }
    return 0;
}