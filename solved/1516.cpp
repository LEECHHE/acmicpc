#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int build[501];
int ans[501][501] = { 0 };
vector<int> prerequiste[501];
int main(){
    int n; scanf("%d",&n);
    for( int i = 1 ; i <= n ; ++i ){
        scanf("%d", &build[i]);
        int indegree = 0;
        while(1){
            int temp; scanf("%d",&temp);
            if( temp < 0 ){
                if( indegree == 0 ){
                    prerequiste[0].push_back(i);
                }
                break;
            }
            else{
                prerequiste[temp].push_back(i);
                ++indegree;
            }
        }
    }
    queue<int> list;
    list.push(0);
    ans[0][0] = build[0];
    while(!list.empty()){
        int current = list.front(); list.pop();
        for ( auto p : prerequiste[current] ){
            if( ans[0][p] < ans[0][current]+build[p] ){
                ans[0][p] = ans[0][current]+build[p];
                list.push(p);
            }
        }
    }
    for( int i = 1 ; i <= n ; ++i )
        printf("%d\n", ans[0][i]);
    return 0;
}