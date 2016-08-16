#include<cstdio>
using namespace std;

int result = 0;
int n, m;
bool virus[100] = { false };
bool com[100][100] = { false };
void infect(int i);
int main(){
    scanf("%d%d", &n, &m);
    for( int i = 0 ; i < m ; ++i ){
        int a,b; scanf("%d%d", &a,&b);
        com[a-1][b-1] = com[b-1][a-1] = true;
    }
    infect(0);
    printf("%d", result-1);
    return 0;
}
void infect(int i){
    if(virus[i]) return;
    virus[i] = true;
    ++result;
    for( int j = 0; j < n; ++j ){
        if( com[i][j] ) infect(j);
    }
}