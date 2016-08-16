#include <cstdio>
using namespace std;

int main () {
    int winner = 0;
    int score = 0;
    
    for ( int i = 0 ; i < 5 ; i++ ){
        int sum = 0;
        for ( int j = 0 ; j < 4 ; j++ ){
            int temp;
            scanf("%d", &temp);
            sum += temp;
        }
        if ( sum > score ){
            score = sum;
            winner = i + 1;
        }
    }
    printf("%d %d", winner, score );
}