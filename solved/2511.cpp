#include<cstdio>
using namespace std;

int cardA[10],cardB;
int main(){
    int scoreA = 0, scoreB = 0;
    char last = 'D';
    for( int i = 0 ; i < 10 ; ++i ) scanf("%d",&cardA[i]);
    for( int i = 0 ; i < 10 ; ++i ){
        scanf("%d",&cardB);
        if(cardB > cardA[i]){
            scoreB += 3;
            last = 'B';
        }
        else if( cardB < cardA[i]){
            scoreA += 3;
            last = 'A';
        }
        else{
            scoreA++; scoreB++;
        }
    }
    printf("%d %d\n", scoreA, scoreB);
    if( scoreA > scoreB ) last = 'A';
    else if( scoreA < scoreB ) last = 'B';
    printf("%c",last);
    return 0;
}