#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int parent[1000000];
int rnk[1000000];
int find(int u){
    if( parent[u] == u ) return u;
    else return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u), v = find(v);
    if( u == v ) return;
    if( rnk[u] < rnk[v] ) swap(u,v);
    parent[v] = u;
    if( rnk[u] == rnk[v] ){
        rnk[u]++;
    }
}
int main(){
    int t; scanf("%d",&t);
    for( int cse = 1 ; cse <= t ; ++cse ){
        printf("Scenario %d:\n",cse);
        int n,k; scanf("%d%d",&n,&k);
        for( int i = 0 ; i < n ; ++i ){
            parent[i] = i;
        }
        memset(rnk, 0, sizeof(rnk));
        for( int i = 0 ; i < k ; ++i ){
            int a,b; scanf("%d%d",&a,&b);
            merge(a,b);
        }
        int m; scanf("%d",&m);
        for( int i = 0 ; i < m ; ++i ){
            int a,b; scanf("%d%d",&a,&b);
            printf("%d\n", find(a) == find(b));
        }
        printf("\n");
    }
    return 0;
}