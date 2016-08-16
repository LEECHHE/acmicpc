#include <cstdio>
using namespace std;

int main(){
    int n,m; scanf("%d%d",&n,&m);
    int card[100];
    for( int i = 0 ; i < n ; ++i ) scanf("%d",&card[i]);
    int ret = 300001;
    for( int i = 0 ; i < n-2 ; ++i ){
        for( int j = i+1 ; j < n-1 ; ++j ){
            for( int k = j+1 ; k < n ; ++k ){
                int cur = m-card[i]-card[j]-card[k];
                if( cur >= 0 && ret > cur ){
                    ret = cur;
                    if( ret == 0 ) break;
                }
            }
            if( ret == 0 ) break;
        }
        if( ret == 0 ) break;
    }
    printf("%d", m-ret);
    return 0;
}