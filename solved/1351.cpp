#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
map<ll,ll> dp;
int p,q;
ll solve(ll n){
    if ( dp[n] ) return dp[n];
    return dp[n] = solve(n/p)+solve(n/q);
}
int main(){
    ll n; cin >> n >> p >> q;
    dp[0] = 1;
    cout << solve(n);
    return 0;
}