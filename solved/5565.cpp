#include <cstdio>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    
    for ( int i = 0 ; i < 9 ; i++ ){
        int temp;
        scanf("%d", &temp);
        T -= temp;
    }
    printf("%d", T);
    return 0;
}