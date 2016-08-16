#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> seq(n);
    for( int i = 0 ; i < n ; i += scanf("%d",&seq[i]));
    int ret = 9001;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = i+1 ; j < n ; ++j ){
            ret = min(ret,seq[j]-seq[i]);
            if( ret < 0 ) break;
        }
        if( ret < 0 ) break;
    }
    ret < 0 ? printf("no") : printf("yes");
    return 0;
}