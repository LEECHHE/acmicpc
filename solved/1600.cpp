#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> intPair;
typedef pair<intPair, int> State;
int k, w, h;
int grid[205][205];
int visited[205][205][35] = { 0 };
int dx[12] = { 0, 0, 1, -1 , 2, 2, 1, 1, -1, -1, -2, -2};
int dy[12] = { 1, -1, 0, 0 , 1, -1, 2, -2, 2, -2, 1, -1};

bool isValid(int x, int y) {
	return 0 <= x && x < h && 0 <= y && y < w;
}

int main() {
	scanf("%d", &k);
	scanf("%d%d", &w, &h);
	for (int i = 0 ; i < h ; ++i) {
		for( int j = 0 ; j < w ; ++j) {
			scanf("%d", &grid[i][j]);
			for ( int k = 0 ; k < 35 ; ++k) {
				visited[i][j][k] = grid[i][j] ? -1 : INT_MAX;
			}
		}
	}

	queue<State> q;
	q.push(State(intPair(0, 0), k));
	visited[0][0][k] = 0;
	int step = 0;
	int answer = -1;
	while(!q.empty()) {
		int count = q.size();
		for (int i = 0 ; i < count ; ++i) {
			State curState = q.front();
			q.pop();
			intPair curPos = curState.first;
			int jumpRemain = curState.second;
			printf("State(%d,%d)%d\n", curPos.first, curPos.second, jumpRemain);
			if (curPos.first == h - 1 && curPos.second == w - 1) {
				answer = step;
				break;
			}

			for (int d = 0 ; d < 12 ; ++d) {
				int nextX = curPos.first + dx[d];
				int nextY = curPos.second + dy[d];
				if (d >= 4 && jumpRemain <= 0) {
					break;
				}
				if (!isValid(nextX, nextY)) {
					continue;
				}
				int jumpIndex = jumpRemain - (d >= 4);
				if (visited[nextX][nextY][jumpIndex] < INT_MAX) {
					continue;	
				}
				visited[nextX][nextY][jumpIndex] = step + 1;
				q.push(State(intPair(nextX, nextY), jumpIndex));
			}
		}
		if (answer >= 0) {
			break;
		}
		++step;
	}
	printf("%d", answer);

	return 0;
}
