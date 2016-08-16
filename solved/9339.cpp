#include <cstdio>
#include <utility>
#include <map>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int k; scanf("%d",&k);
        map<int, bool> record;
        for( int i = 0 ; i < k ; ++i ){
            int nr; scanf("%d",&nr);
            record.insert(make_pair(nr, 1));
        }
        int n; scanf("%d",&n);
        int best = -1;
        int certificate = 0;
        int best_record = 1500;
        for( int i = 0 ; i < n ; ++i ){
            int nr,h,m; scanf("%d%d%d",&nr,&h,&m);
            if( h < 0 || m < 0 ) continue;
            if( record.count(nr) ){
                int cur = h*60+m;
                if( cur < best_record ){
                    best_record = cur;
                    best = nr;
                }
                if( cur <= 360 ){
                    ++certificate;
                }
            }
        }
        printf("%d %d\n", best, certificate);
    }
    return 0;
}