#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
int main(){
    ll n,m; scanf("%lld%lld",&n,&m);
    vector<ll> h;
    h.push_back(0);
    for ( ll i = 0 ; i < n ; ++i ){
        ll t; scanf("%lld",&t);
        h.push_back(t);
    }
    sort(h.begin(), h.end());
    
    ll len = (ll)h.size();
    vector<pair<ll, ll>> diff;
    
    ll cnt = 1;
    for( ll i = len-1 ; i > 0 ; --i ){
        ll curDif = h[i]-h[i-1];
        if( curDif == 0 ) cnt++;
        else{
            diff.push_back(make_pair(curDif, cnt));
            cnt = 1;
        }
    }
    
    len = (ll)diff.size();
    ll ret = h.back();
    cnt = 0;
    for( ll i = 0 ; i < len ; ++i ){
        cnt += diff[i].second;
        if( m >= diff[i].first * cnt ){
            ret -= diff[i].first;
            m -= diff[i].first * cnt;
        }
        else{
            ll height =ll(ceil((double)m / cnt));
            ret -= height;
            m -= height * cnt;
        }

        if( m <= 0 ) break;
    }
    printf("%lld", ret);
    return 0;
}