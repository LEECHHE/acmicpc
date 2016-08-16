#include <cstdio>
using namespace std;

int piece[6] = { 1, 1, 2, 2, 2, 8 };
int main(){
    for ( int i = 0 ; i < 6 ; i++ ){
        int temp;
        scanf("%d", &temp);
        printf("%d ", piece[i] - temp);
    }
    return 0;
}