#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	while(b){
		ll t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	ll a, b; scanf("%lld%lld",&a,&b);
	ll ra = sqrt(a), rb = sqrt(b);
	if( rb-ra == 0 )
		printf("0");
	else{
		ll g = gcd(rb-ra,b-a);
		printf("%lld/%lld",(rb-ra)/g,(b-a)/g);
	}
	return 0;
}