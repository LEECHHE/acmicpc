#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
map<string,int> idx;
vector<int> adj[40];
void search(bool* visited, int cur){
    for( auto next : adj[cur] ){
        if(visited[next]) continue;
        visited[next] = true;
        search(visited,next);
    }
}
int main(){
    int t = 0;
    while(++t){
        int n; cin >> n;
        if( n == 0 ) break;
        for( int i = 0 ; i < 40 ; ++i ) adj[i].clear();
        idx.clear();
        int cnt = 0;
        for( int i = 0 ; i < n ; ++i ){
            string from, to;
            cin >> from >> to;
            if( !idx[from] ) idx[from] = cnt++;
            if( !idx[to] ) idx[to] = cnt++;
            adj[idx[from]].push_back(idx[to]);
        }
        bool visited[40] = { false };
        int ret = 0;
        for( int i = 0 ; i < cnt ; ++i ){
            if(!visited[i]){
                visited[i] = true;
                ++ret;
                search(visited,i);
            }
        }
        cout << t << " " << ret << endl;
    }
    return 0;
}