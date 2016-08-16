#include <cstdio>
using namespace std;

int main(){
    int amount[2][10001] = { 0 };
    int coin[100];
    int n,k; scanf("%d%d", &n,&k);
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d", &coin[i]);
    }
    for( int money = 0 ; money <= k ; money += coin[0] ){
        amount[0][money] = 1;
//        printf("(0,%d)%d ", money, amount[0][money]);
    }
    
    for( int kind = 1 ; kind < n ; ++kind ){
        for( int money = 0 ; money <= k ; ++money ){
            amount[kind%2][money] = amount[(kind+1)%2][money];
            if( money - coin[kind] >= 0 )
                amount[kind%2][money] += amount[kind%2][money-coin[kind]];
//            printf("(%d,%d)%d ", kind, money, amount[kind%2][money]);
        }
//        printf("\n");
    }
    printf("%d", amount[(n-1)%2][k]);
    
    return 0;
}