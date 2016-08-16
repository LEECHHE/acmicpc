#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int,int> intPair;
typedef pair<int,intPair> state;
int fat[25];
int joy[25];
int n;
int process(int p){
	int f = 0;
	int people = p;
	int idx = 1;
	while(people){
		if(people%2) f += fat[idx];
		people /= 2;
		++idx;
	}
	if( f >= 100 ) return 0;
	int ret = 0;
	idx = 1;
	while(p){
		if(p%2) ret += joy[idx];
		p/=2;
		++idx;
	}
	return ret;
}
int max(int a, int b) { return a>b?a:b; }
int main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; ++i ) scanf("%d",&fat[i]);
	for( int i = 1 ; i <= n ; ++i ) scanf("%d",&joy[i]);
	int ret = 0;
	for( int p = 1 ; p <= 1<<n ; ++p ){
		ret = max(ret,process(p));
	}
	printf("%d",ret);
	return 0;
}