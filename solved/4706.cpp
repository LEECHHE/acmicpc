#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double ta, tb;
	while(1){
		scanf("%lf%lf",&ta,&tb);
		if( ta == 0 && tb == 0 ) break;
		printf("%.3lf\n",sqrt(1-(tb/ta)*(tb/ta)));
	}
	return 0;
}
