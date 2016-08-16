#include <cstdio>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    bool eratos[101] = { false };
    for( int i = 2 ; i < 101 ; ++i ) eratos[i] = true;
    for ( int i = 2 ; i < 101 ; ++i ){
        if( eratos[i] ){
            for( int j = 2 ; j*i < 101 ; ++j ){
                eratos[j*i] = false;
            }
        }
    }
    int result = 0;
    while(n--){
        int k; scanf("%d", &k);
        if( eratos[k] ) result++;
    }
    printf("%d", result);
    return 0;
}