#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<double, double> doublePair;
//const double epsilon = 0.0000000001;
int main(){
    while(1){
        int nx, ny; double w;
        scanf("%d%d%lf",&nx,&ny,&w);
        if( nx == 0 && ny == 0 && w == 0 ) break;
        vector<doublePair> x, y;
        for( int i = 0 ; i < nx ; ++i ){
            double xi; scanf("%lf",&xi);
            x.push_back(make_pair(xi-w/2,xi+w/2));
        }
//        x.push_back(make_pair(75, 75+w));
        for( int i = 0 ; i < ny ; ++i ){
            double xi; scanf("%lf",&xi);
            y.push_back(make_pair(xi-w/2,xi+w/2));
        }
//        y.push_back(make_pair(100, 100+w));
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        bool ret = x[0].first <= 0.0;
        if( ret ){
            for (int i = 1; i < nx; ++i) {
                if( x[i].first > x[i-1].second ){
                    ret = false;
                    break;
                }
            }
            if( ret ) ret = x.back().second >= 75.0;
        }
        if ( ret ){
            ret = y[0].first <= 0.0;
            if( ret ){
                for (int i = 1; i < ny; ++i) {
                    if( y[i].first > y[i-1].second ){
                        ret = false;
                        break;
                    }
                }
            }
            if ( ret ) ret = y.back().second >= 100.0;
        }
        if( ret ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}