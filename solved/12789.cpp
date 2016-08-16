#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int n; scanf("%d",&n);
	queue<int> seq;
	int t;
	for( int i = 0 ; i < n ; ++i ){
		scanf("%d",&t);
		seq.push(t);
	}
	stack<int> wait;
	wait.push(0);
	int goal = 1;
	while(!seq.empty() || !wait.empty()){
		if( seq.empty() &&  wait.top() != goal ) break;
		if ( seq.front() == goal ){
			seq.pop();
			++goal;
		}
		else if( wait.top() == goal ){
			wait.pop();
			++goal;
		}
		else{
			if( seq.empty() ) break;
			wait.push(seq.front());
			seq.pop();
		}
	}
	if( goal == n+1 ) printf("Nice");
	else printf("Sad");
	return 0; 
}