#include <cstdio>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        char grill[12][12];
        char filpped[12][12];
        int h,w;
        scanf("%d%d", &h,&w);
        for( int i = 0 ; i < h ; ++i ) scanf("%s", grill[i]);
        for( int i = 0 ; i < h ; ++i ){
            for( int j = 0 ; j < w ; ++j ){
                filpped[i][j] = grill[i][w-j-1];
            }
        }
        for( int i = 0 ; i < h ; ++i ){
            for ( int j = 0 ; j < w ; ++j){
                printf("%c", filpped[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}