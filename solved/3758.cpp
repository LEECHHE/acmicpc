#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int, int> intPair; //점수, 시간
int score[101] = { 0 };
int cnt[101] = { 0 };
int last[101] = { 0 };
int main(){
    int cse; scanf("%d",&cse);
    while(cse--){
        int n, k, t, m; scanf("%d%d%d%d",&n,&k,&t,&m);
        intPair record[101][101];
        memset(record, 0, sizeof(record));
        memset(score, 0, sizeof(score));
        memset(cnt, 0, sizeof(cnt));
        memset(last, 0, sizeof(last));
        for( int i = 0 ; i < m ; ++i ){
            int id,j,s; scanf("%d%d%d",&id,&j,&s);
            cnt[id]++;
            last[id] = i;
            if( record[id][j].first <= s ){
                score[id] += s - record[id][j].first;
                record[id][j].first = s;
                record[id][j].second = i;
            }
        }
        
        int ret = 1;
        int myScore = score[t];
        vector<int> sameScore;
        for( int i = 1 ; i <= n ; ++i ){
            if( i == t ) continue;
            if( myScore < score[i] ){
                ret++;
            }
            else if( myScore == score[i] ){
                sameScore.push_back(i);
            }
        }
        
        for( auto team : sameScore ){
            if( cnt[team] < cnt[t] ) ret++;
            else if( cnt[team] == cnt[t] ){
                if( last[team] < last[t] )
                    ret++;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}