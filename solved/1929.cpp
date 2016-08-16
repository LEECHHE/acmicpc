#include<iostream>
using namespace std;

int main(){
    bool eratoseutenes[1000001];
    int m,n; scanf("%d%d",&m,&n);
    for( int i = 0 ; i <= n ; ++i ) eratoseutenes[i] = true;
    int j = 2;
    for( ; j <= n ; ++j ){
        if( eratoseutenes[j] ){
            if( j >= m )
                printf("%d\n",j);
            for( int k = 2 ; k*j <= n ; ++k ){
                eratoseutenes[k*j] = false;
            }
        }
    }
    return 0;
}