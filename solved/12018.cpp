#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n,m; scanf("%d%d",&n,&m);
    vector<int> needed;
    for( int i = 0 ; i < n ; ++i ){
        int p,l; scanf("%d%d",&p,&l);
        int seq[100];
        for( int i =0 ; i < p ; i += scanf("%d",&seq[i]));
        sort(seq,seq+p);
        if( p-l < 0 ){
            needed.push_back(1);
        }
        else{
            needed.push_back(seq[p-l]);
        }
    }
    sort(needed.begin(), needed.end());
    int cnt = 0;
    for( int i = 0 ; i < n ; ++i ){
        m -= needed[i];
        if( m < 0 ) break;
        ++cnt;
    }
    printf("%d",cnt);
    return 0;
}