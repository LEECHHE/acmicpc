#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int main(){
	int pattern[] = { 1, 2, 3, 4, 5 };
	int n; scanf("%d", &n);
	for (int k = 1; k <= n; ++k ){
		bool retake = true;
		int temp[10];
		for (int j = 0; j < 10; ++j)
			scanf("%d", &temp[j]);
		for (int j = 0; j < 10; ++j){
			if (temp[j] != pattern[j % 5]){
				retake = false;
				break;
			}
		}
		if (retake) printf("%d\n", k);
	}

	return 0;
}