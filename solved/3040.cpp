#include <cstdio>
using namespace std;
int main(){
    int sum = -100;
    int dwf[9];
    for( int i = 0 ; i < 9 ; ++i ){
        int temp; scanf("%d",&temp);
        dwf[i] = temp;
        sum += temp;
    }
    int f1 = -1,f2 = -1;
    for( int i = 0; i < 9 ; ++i ){
        for ( int j = i+1 ; j < 9; ++j){
            if( dwf[i]+dwf[j] == sum ){
                f1 = i; f2 = j;
                break;
            }
        }
        if( f1 > 0 ) break;
    }
    for ( int i = 0 ; i < 9 ; ++i ){
        if( i == f1 || i == f2 ) continue;
        printf("%d\n",dwf[i]);
    }
    return 0;
}