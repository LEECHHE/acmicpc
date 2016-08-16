#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	int cards[101][101];
	int wins[101] = { 0 };
	int maxWin = 0;
	for( int i = 1 ; i <= n ; ++i ) {
		for( int j = 1 ; j <= m ; ++j ){
			scanf("%d",&cards[i][j]);
		}
		sort(cards[i]+1, cards[i]+1+m);
	}
	for( int i = m ; i >= 1 ; --i ){
		vector<int> winners;
		int most = 0;
		for( int p = 1; p <= n ; ++p ){
			if( cards[p][i] > most ){
				winners.clear();
				winners.push_back(p);
				most = cards[p][i];
			}
			else if( cards[p][i] == most ){
				winners.push_back(p);
			}
		}

		for( auto p : winners ){
			maxWin = max(++wins[p], maxWin);
		}
	}

	for( int i = 1 ; i <= n ; ++i ){
		if( wins[i] == maxWin ) printf("%d ", i);
	}

	return 0;
}

