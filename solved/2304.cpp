#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> intPair;
int main(){
    int n; scanf("%d",&n);
    int mh = -1;
    vector<intPair> bar(n);
    for ( int i = 0 ; i < n ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        mh = max(mh,b);
        bar[i] = intPair(a,b);
    }
    sort(bar.begin(), bar.end());
    int l = 0, r = n;
    int bh = 0,bi = 0;
    int ret = 0;
    for( int i = 0 ; i < n ; ++i ){
        if( bh <= bar[i].second ){
            ret += bh*(bar[i].first-bi);
            bi = bar[i].first;
            bh = bar[i].second;
            
            if( mh == bar[i].second ){
                l = bar[i].first;
                break;
            }
        }
    }
    bh = 0; bi = bar.back().first;
    for( int i = n-1 ; i >= 0 ; --i ){
        if( bh <= bar[i].second ){
            ret += bh*(bi-bar[i].first);
            bi = bar[i].first;
            bh = bar[i].second;
            if( mh == bar[i].second ){
                r = bar[i].first;
                break;
            }
        }
    }
    printf("%d", ret+(r-l+1)*mh);
    return 0;
}