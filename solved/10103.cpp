#include<cstdio>
#include<stack>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int main(){
	int n; scanf("%d", &n);
	int a = 100, b = 100;
	for(int i = 0 ; i < n ; ++i){
		int s1, s2; scanf("%d%d", &s1, &s2);
		if (s1 < s2) a -= s2;
		else if (s2 < s1) b -= s1;
	}
	printf("%d\n%d", a, b);

	return 0;
}