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

const int INF = (1 << 31)-1;
bool isPrime[10000] = { false };
vector<int> primes;
void erathos(){
    isPrime[0] = isPrime[1] = false;
    for( int i = 2 ; i < 10000 ; ++i ){
        if( isPrime[i] ){
            if( i > 1000)
                primes.push_back(i);
            for( int n = i * 2 ; n < 10000 ; n += i ){
                isPrime[n] = false;
            }
        }
    }
}
vector<int> adj[1061];
int pow10( int i ){
    if( i == 0 ) return 1;
    return 10 * pow10(i-1);
}
bool isConnected(int a, int b){
    int digit[2][4];
    int current[2] ={ a, b };
    for( int d = 0 ; d < 4 ; ++d ){
        digit[0][d] = current[0] / pow10(3-d);
        digit[1][d] = current[1] / pow10(3-d);
        
        current[0] %= pow10(3-d);
        current[1] %= pow10(3-d);
    }
    int res = 0;
    for( int i = 0 ; i < 4 ; ++i ){
        res += digit[0][i] == digit[1][i];
    }
    return res == 3;
}
void makegraph(){
    int n = (int)primes.size();
    for( int i = 0 ; i < n-1 ; ++i ){
        for( int j = i + 1 ; j < n ; ++j ){
            if( isConnected(primes[i], primes[j]) ){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}
// adj : primes의 인덱스 그래프.
int cost[1061];
int ret = INF;
void dfs(int current, int target, int step){
    if( primes[current] == target ){
        ret = min ( ret, step );
        return;
    }
    if( cost[current] < step ) return;
    
    cost[current] = step;
    
    for ( auto node : adj[current] ){
        dfs( node, target, step + 1 );
    }
}
int getStep(int number, int target){
    int idx = (int)(find(primes.begin(), primes.end(), number ) - primes.begin());
    dfs( idx, target , 0);
    return ret;
}

int main(){
    for( int i = 0 ; i < 10000 ; ++i ) isPrime[i] = true;
    erathos();
    makegraph();
   
    int t; scanf("%d",&t);
    while(t--){
        for( int i = 0 ; i < 1061 ; ++i ) cost[i] = INF;
        int a,b; scanf("%d%d",&a,&b);
        ret = INF;
        ret = a == b ? 0 : getStep(a, b);
        
        if( ret >= INF ) printf("Impossible\n");
        else printf("%d\n", ret);
    }
    return 0;
}