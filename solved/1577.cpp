#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
vector< pair< pair<int, int>, pair<int, int> > > disconnected;
bool isDisconnected(int a, int b, int c, int d){
    for( auto edge : disconnected ){
        if( (edge.first.first == a && edge.first.second == b )
           && (edge.second.first == c && edge.second.second == d ) ){
            return true;
        }
        if( (edge.first.first == c && edge.first.second == d )
           && (edge.second.first == a && edge.second.second == b ) ){
            return true;
        }
    }
    return false;
}
unsigned long long dp[102] = { 0 };
int main(){
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for( int i = 0 ; i < k ; ++i ){
        int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
        disconnected.push_back(make_pair(make_pair(a+1, b+1), make_pair(c+1, d+1)));
    }
    dp[1] = 1;
    for( int i = 1 ; i <= m+1 ; ++i ){
        for( int j = 1 ; j <= n+1 ; ++j ){
            if( isDisconnected(j, i-1, j, i) ){
                dp[j] = 0;
            }
            if( !isDisconnected(j-1, i, j, i)){
                dp[j] += dp[j-1];
            }
//            printf("(%d,%d):%lld\t", j-1, i-1, dp[j]);
        }
//        printf("\n");
    }
    printf("%lld", dp[n+1]);
    return 0;
}