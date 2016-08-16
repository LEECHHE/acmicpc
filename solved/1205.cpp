#include <cstdio>
using namespace std;
int main(){
    int n,s,p; scanf("%d%d%d",&n,&s,&p);
    int seq[51];
    for( int i = 0 ; i < n ; ++i ) scanf("%d",&seq[i]);
    int ret = 1;
    int same = 0;
    int i;
    for ( i = 0; i < n ; ++i) {
        if( seq[i] < s ) break;
        if( seq[i] > s ) ++ret;
        else{
            while (i < n && seq[i] == s) {
                ++same;
                ++i;
            }
            break;
        }
    }
    if(ret-1+same < p ){
        printf("%d", ret);
    }
    else{
        printf("-1");
    }
    return 0;
}