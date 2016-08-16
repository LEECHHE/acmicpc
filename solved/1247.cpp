#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
    for( int i = 0 ; i < 3 ; ++i ){
        priority_queue<ll, vector<ll>, greater<ll>> pos;
        priority_queue<ll> neg;
        int n; scanf("%d",&n);
        while(n--){
            ll t; scanf("%lld", &t);
            if( t > 0 ) pos.push(t);
            else if( t < 0 ) neg.push(t);
        }
        
        while(!pos.empty() && !neg.empty()){
            ll p = pos.top(); pos.pop();
            ll n = neg.top(); neg.pop();
            p += n;
            if( p > 0 ) pos.push(p);
            else if( p < 0 ) neg.push(p);
        }
        
        if( pos.empty() && neg.empty() ){
            printf("0\n");
        }
        else if( pos.empty() ){
            printf("-\n");
        }
        else{
            printf("+\n");
        }
    }
    return 0;
}