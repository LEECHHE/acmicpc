#include <cstdio>
using namespace std;

struct Man{
    int weight;
    int height;
    int rank;
};
int main () {
    struct Man list[50];
    int N;
    scanf("%d", &N);
    
    for( int i = 0 ; i < N ; i++ )
    {
        scanf("%d %d", &list[i].weight, &list[i].height);
        list[i].rank = 1;
    }
    
    for ( int i = 0; i < N ; i++ ){
        for ( int j = 0 ; j < N ; j++ ){
            if ( list[i].weight < list[j].weight && list[i].height < list[j].height){
                list[i].rank++;
            }
        }
    }
    for ( int i = 0 ; i < N ; i++ ){
        printf("%d ", list[i].rank );
    }
    return 0;
}