#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int score[200][3];
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d%d%d",&score[i][0],&score[i][1],&score[i][2]);
    }
    int total[200] = { 0 };
    for( int round = 0 ; round < 3 ; ++round ){
        int appeared[101] = { false };
        for( int player = 0 ; player < n ; ++player ){
            appeared[score[player][round]]++;
        }
        for( int player = 0 ; player < n ; ++player ){
            if(appeared[score[player][round]] <= 1){
                total[player] += score[player][round];
            }
        }
    }
    for( int player = 0 ; player < n ; ++player ){
        printf("%d\n", total[player]);
    }
    return 0;
}