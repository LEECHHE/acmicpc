#include<iostream>
using namespace std;
int cnt[5]={0};
int belongs_to(int a, int b){
	if( a > 0 && b > 0 ) return 1;
	if( a < 0 && b > 0 ) return 2;
	if( a < 0 && b < 0 ) return 3;
	if( a > 0 && b < 0 ) return 4;
	return 0;
}
int main(){
	int n; scanf("%d",&n);
	int a,b;
	for( int i = 0 ; i < n ; ++i ){
		scanf("%d%d",&a,&b);
		cnt[belongs_to(a,b)]++;
	}
	for( int i = 1 ; i <= 4 ; ++i ){
		printf("Q%d: %d\n",i,cnt[i]);
	}
	printf("AXIS: %d", cnt[0]);
	return 0;
}