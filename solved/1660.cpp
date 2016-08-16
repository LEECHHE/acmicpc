#include <cstdio>
#include <vector>
using namespace std;

int dp[300001];
vector<int> bullets;
int getMin(int index);
int main(){
    for ( int i = 1 ;  ; ++i ){
        int n = i * (i+1) * (i+2) / 6;
        if ( n > 300000 ) break;
        bullets.push_back(n);
    }
    int n; scanf("%d", &n);
    for ( int i = 1 ; i <= n ; dp[i++] = 300001);
    dp[0] = 0;
    for ( int i = 1 ; i <= n ; ++i ){
        dp[i] = getMin(i)+1;
    }
    printf("%d", dp[n]);
    return 0;
}
int getMin( int index ){
    int min = 300001;
    for( auto it = bullets.begin() ; it != bullets.end() ; ++it ){
        if( index - (*it) < 0 ) break;
        if( min > dp[index-(*it)] ) min = dp[index-(*it)];
    }
    return min;
}