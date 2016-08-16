#include<cstdio>
using namespace std;

void visitZ(int n, int row, int col, int& result);
int pow2(int n);
int r,c;
int main(){
    while(1){
        int N;
        if(scanf("%d%d%d", &N,&r,&c) == -1) break;
        int ans = 0;
        visitZ(N, 0, 0, ans);
        printf("%d\n", ans);
    }
    return 0;
}
int pow2(int n){
    if( n == 0 ) return 1;
    else return 2*pow2(n-1);
}
void visitZ(int n, int row, int col, int& result){
    if( n == 0 ) return;
    int isRight = 0;
    int isBottom = 0;
    if( c >= col + pow2(n-1) ) isRight = 1;
    if( r >= row + pow2(n-1) ) isBottom = 1;
    result += isBottom*pow2(n-1)*pow2(n) + isRight*pow2(n-1)*pow2(n-1);
    visitZ(n-1, row+isBottom*pow2(n-1), col+isRight*pow2(n-1), result);   
}