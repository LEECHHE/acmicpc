#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;
bool isPrime[2000];
int adj[50][50];
vector<int> odd, even;
vector<int> aMatch, bMatch;
vector<bool> visited;
vector<int> ans;
bool isOdd;
bool dfs(int b){
    if( visited[b] ) return false;
    visited[b] = true;
    int len = (int)odd.size();
    for( int next = 0 ; next < len ; ++next ){
        if((isOdd && adj[b][len+next] > 0) || (!isOdd && adj[len+b][next] > 0)){
            if( bMatch[next] == -1 || dfs(bMatch[next]) ){
                aMatch[b] = next;
                bMatch[next] = b;
                return true;
            }
        }
    }
    return false;
}
void bipartiteMatch(int idx){
    int len = (int)odd.size();
    if( isOdd ){
        if(!isPrime[odd[0]+even[idx]]) return;
    }
    else{
        if(!isPrime[even[0]+odd[idx]]) return;
    }
    aMatch = vector<int>(len,-1);
    bMatch = vector<int>(len,-1);

    int matching = 1;
    aMatch[0] = idx;
    bMatch[idx] = 0;
    if(isOdd){
        for( int i = 0 ; i < len ; ++i ){
            adj[0][len+i] *= -1;
            adj[len+i][0] *= -1;
            adj[len+idx][i] *= -1;
            adj[i][len+idx] *= -1;
        }
    }
    else{
        for( int i = 0 ; i < len ; ++i ){
            adj[len+i][idx] *= -1;
            adj[idx][len+i] *= -1;
            adj[len][i] *= -1;
            adj[i][len] *= -1;
        }
    }

    for( int start = 1 ; start < len ; ++start ){
        visited = vector<bool>(len,false);
//        visited[idx] = true;
        if( dfs(start) ){
            ++matching;
        }
    }
    if(matching == len){
        isOdd? ans.push_back(even[idx]) : ans.push_back(odd[idx]);
    }
//        for( int i = 0 ; i < odd.size() ; ++i ){
//            printf("(%d,%d)idx(%d,%d) ",odd[i],even[aMatch[i]],i,aMatch[i] );
//        }
//    printf("\n");

    if(isOdd){
        for( int i = 0 ; i < len ; ++i ){
            adj[0][len+i] *= -1;
            adj[len+i][0] *= -1;
            adj[len+idx][i] *= -1;
            adj[i][len+idx] *= -1;
        }
    }
    else{
        for( int i = 0 ; i < len ; ++i ){
            adj[len+i][idx] *= -1;
            adj[idx][len+i] *= -1;
            adj[len][i] *= -1;
            adj[i][len] *= -1;
        }
    }
}
int main(){
    int n; scanf("%d",&n);
    memset(isPrime, true, sizeof(isPrime));

    for( int i = 2 ; i < 2000 ; ++i ){
        if(isPrime[i]){
            for( int j = i*2 ; j < 2000 ; j += i ) isPrime[j] = false;
        }
    }
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        if( i == 0 ) isOdd = t%2;
        t%2? odd.push_back(t) : even.push_back(t);
    }
    if( odd.size() != even.size() ){
        printf("-1");
        return 0;
    }
    int len = (int)odd.size();
    for( int i = 0 ; i < len ; ++i ){
        for( int j = 0 ; j < len ; ++j ){
            if( isPrime[odd[i] + even[j]] ){
                adj[i][len+j] = adj[len+j][i] = 1;
            }
        }
    }
    for( int i = 0 ; i < len ; ++i ){
        bipartiteMatch(i);
    }
    if(ans.empty()) ans.push_back(-1);
    sort(ans.begin(), ans.end());
    for( auto ret : ans ){
        printf("%d ",ret);
    }
    return 0;
}