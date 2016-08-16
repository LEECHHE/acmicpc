#include<iostream>
using namespace std;

int main(){
	int t; scanf("%d",&t);
	while(t--){
		int s[2][4];
		for( int j = 0 ; j < 2 ; ++j ){
			for( int i = 0 ; i < 4 ; ++i ){
				scanf("%d",&s[j][i]);
			}
		}
		for( int i = 0 ; i < 4 ; ++i ) s[0][i] += s[1][i];
		int ret = (s[0][0] < 1 ? 1 : s[0][0])+5*(s[0][1] < 1 ? 1 : s[0][1])+2*((s[0][2]<0?0:s[0][2]) + s[0][3]);
		printf("%d\n",ret);
	}
	return 0;
}