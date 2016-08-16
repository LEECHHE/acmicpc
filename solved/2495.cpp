#include<cstdio>
#include<stack>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int main(){
	char current;
	int count = 1;
	int answer = -1;

	for (int i = 0; i < 3; ++i){
		char number[9]; scanf("%s", number);
		current = number[0];
		answer = -1;
		count = 1;

		for (int j = 1; j < 8; ++j){
			if (current != number[j]){
				current = number[j];
				if (answer < count){
					answer = count;
				}
				count = 1;
			}
			else
				count++;
		}
		if (answer < count){
			answer = count;
		}
		printf("%d\n", answer);
	}
	return 0;
}