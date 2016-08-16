#include <iostream>
#include <cstring>
using namespace std;
int has;
int target;
int include_all_number(int n){
	bool success = true;
	while(n){
		if( has & (1<<(n%10))){ 
			n /= 10;
			continue;
		}
		success = false;
		break;
	}
	return success;
}
int solve(int k, int cnt){
	if( include_all_number(k) ){
		return cnt;
	}
	else{
		bool split = false;
		int ret = 50;
		int t1 = 0, t2 = 0;
		for( int div=2; div*div <= k ; ++div ){
			if( k % div ) continue;
			t1 = solve(div,cnt+1);
			split = true;
			if( t1 < ret ){
				t2 = solve(k/div,cnt);
				ret = min(ret, t1+t2);
			}
		}
		return split? ret : 100;
	}
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		has = 0;
		int n; scanf("%d", &n);
		for( int i = 0 ; i < n ; ++i ){
			int c; scanf("%d",&c);
			has |= 1<<c;
		}
		int m; scanf("%d",&m);
		for( int i = 0 ; i < m ; ++i ){
			scanf("%d",&target);
			int ret = solve(target,0);
			printf("%d\n", ret < 50 ? ret : -1 );
		}
	}
	return 0;
}