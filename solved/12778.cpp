#include <iostream>

using namespace std;

int main(){
	int t; scanf("%d",&t);

	while(t--){
		int m; char q[2]; scanf("%d%s",&m,q);
		for( int i = 0 ; i < m ; ++i ){
			if( q[0] == 'C' ){
				char c[2]; scanf("%s",c);
				printf("%d ",c[0]-'A'+1);
			}
			else {
				int c; scanf("%d", &c);
				printf("%c ", c+'A'-1);
			}
		}
		printf("\n");
	}

	return 0;
}