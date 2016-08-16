#include <cstdio>
using namespace std;

int score[1000];
int main(){
    int N;
    scanf("%d", &N);
    
    int max = 0;
    for ( int i = 0 ; i < N ; i++ ){
        scanf( "%d", &score[i] );
        if ( score[i] > max )
            max = score[i];
    }
    double sum = 0.0;
    for ( int i = 0 ; i < N ; i++ ){
        sum += (double)score[i] / (double)max * 100;
    }
    printf( "%.2lf", sum / (double)N );
    return 0;
}