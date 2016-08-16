#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    bool seq[101];
    for( int i = 1 ; i <= n ; ++i ){
        int t; scanf("%d",&t);
        seq[i] = t == 1;
    }
    int m; scanf("%d",&m);
    for( int i =0  ; i < m ; ++i ){
        int s, idx; scanf("%d%d",&s,&idx);
        if( s == 1 ){
            int k = idx;
            while (idx<=n) {
                seq[idx] = !seq[idx];
                idx += k;
            }
        }
        else{
            int l = idx-1, r = idx+1;
            seq[idx] = !seq[idx];
            while (l > 0 && r <= n) {
                if( seq[l] == seq[r] ){
                    seq[l] = !seq[l];
                    seq[r] = !seq[r];
                }
                else break;
                --l, ++r;
            }
        }
    }
    for( int i = 1 ; i <= n ; ++i ){
        printf("%d ",seq[i]);
        if( i % 20 == 0 ) printf("\n");
    }
    return 0;
}