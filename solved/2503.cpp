#include<cstdio>
#include<stack>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
bool numbers[1001] = { false };
bool pitch(int iter, int n, int strike, int ball);
int main(){
	for (int i = 100; i < 1000; ++i){
		int dup[3] = { i / 100, i / 10 % 10, i % 10 };
		if (dup[0] == 0 || dup[1] == 0 || dup[2] == 0) continue;
		if (dup[0] == dup[1] || dup[0] == dup[2] ||
			dup[1] == dup[2]) continue;
		numbers[i] = true;
	}

	int n; scanf("%d", &n);
	while (n--){
		int p, s, b; scanf("%d%d%d", &p, &s, &b);
		for (int i = 102; i < 1000; ++i){
			if (!numbers[i]) continue;
			else{
				numbers[i] = pitch(i, p, s, b);
			}
		}
	}
	int ans = 0;
	for (int i = 100; i < 1000; ++i){
		if (numbers[i]) ++ans;
	}
	printf("%d", ans);
	return 0;
}
bool pitch(int iter, int n, int strike, int ball){
	int s = 0;
	int b = 0;
	int n1[3] = { iter / 100, iter / 10 % 10, iter % 10 };
	int n2[3] = { n / 100, n / 10 % 10, n % 10 };
	for (int i = 0; i < 3; ++i){
		if (n1[i] == n2[i]) ++s;
	}
	if (s != strike) return false;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			if (i == j) continue;
			else if (n1[i] == n2[j]) ++b;
		}
	}
	if (b != ball) return false;

	return true;
}