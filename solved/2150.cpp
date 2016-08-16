#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <string>
#include <stack>
using namespace std;
vector<vector<bool>> adj;
vector<int> sccId, discoverd;
vector<bool> finished;
stack<int> st;
int sccCounter, vertexCounter;

int scc(int here, int v){
    int ret = discoverd[here] = vertexCounter++;
    st.push(here);
    for( int there = 1 ; there <= v; ++there ){
        if(adj[here][there] == 0 ) continue;
        
        if( discoverd[there] == -1 ){
            ret = min(ret, scc(there, v)); // tree edge
        }
        else if(discoverd[there] < discoverd[here] && finished[there] != 1){
            ret = min(ret, discoverd[there]);
        }
    }
    
    if( ret == discoverd[here] ){
        while(1){
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            finished[t] = 1;
            if( t == here ) break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> tarjanSCC(int v, int e){
    adj = vector<vector<bool>>(v+1, vector<bool>(v+1));
    finished = vector<bool>(v+1, false);
    sccId = vector<int>(v+1, -1);
    discoverd = vector<int>(v+1, -1);
    sccCounter = vertexCounter = 0;
    for( int i = 0 ; i < e ; ++i ){
        int a,b; scanf("%d%d",&a,&b);
        adj[a][b] = 1;
    }
    for( int i = 1 ; i <= v ; ++i ){
        if( discoverd[i] == -1 ){
            scc(i, v);
        }
    }
    return sccId;
}
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}
int main(){
    int v,e; scanf("%d%d",&v,&e);
    vector<int> ret = tarjanSCC(v,e);
    vector<vector<int>> prints = vector<vector<int>>(sccCounter, vector<int>());
    for( int i = 1 ; i <= v ; ++i ){
        prints[ret[i]].push_back(i);
    }
    sort(prints.begin(), prints.end(), cmp);
    printf("%d\n", sccCounter);
    for( auto connected : prints ){
        for( auto node : connected ){
            printf("%d ",node);
        }
        printf("-1\n");
    }
    return 0;
}