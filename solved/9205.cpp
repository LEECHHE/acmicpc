#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int, int> intPair;
int abs(int k){
    return k > 0 ? k : -k;
}
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int n; scanf("%d",&n);
        intPair seq[105];
        bool adj[105][105];
        for( int i = 0 ; i < n+2 ; ++i ){
            scanf("%d%d", &seq[i].first, &seq[i].second);
            for( int j = i-1 ; j >= 0 ; --j ){
                adj[j][i] = adj[i][j] = (abs(seq[i].first-seq[j].first)+abs(seq[i].second-seq[j].second)) <= 1000;
            }
        }
        for( int k = 0 ; k < n+2 ; ++k ){
            for( int i = 0 ; i < n+2 ; ++i ){
                for( int j = 0 ; j < n+2 ; ++j ){
                    adj[i][j] |= adj[i][k] && adj[k][j];
                }
            }
        }
        adj[0][n+1] ? printf("happy\n") : printf("sad\n");
    }
    return 0;
}