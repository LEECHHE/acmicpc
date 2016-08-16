#include <cstdio>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    int score[101];
    scanf("%d",&score[0]);
    int ret = 0;
    for( int i = 1; i < n ; ++i ){
        scanf("%d",&score[i]);
        if( score[i] <= score[i-1] ){
            for( int j = i-1 ; j >= 0 ; --j ){
                if( score[j+1] > score[j] ) break;
                
                ret += score[j]-score[j+1]+1;
                score[j] = score[j+1]-1;
            }
        }
    }
    printf("%d", ret);
    
    return 0;
}