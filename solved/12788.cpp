#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;
int pen[1005];
bool cmp( const int& a, const int& b){
	return a > b;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int needs = m*k;
	for( int i = 0 ; i < n ; ++i ) scanf("%d",&pen[i]);
	sort( pen, pen+n, cmp);
	//for( int i = 0 ; i < n ; ++i ) printf("%d ",pen[i]);
	int ret = 0;
	while( needs > 0 && ret < n){
		needs -= pen[ret++];
	}
	if( needs > 0 ) printf("STRESS");
	else printf("%d",ret);
	return 0;
}