#include <cstdio>
using namespace std;

int main(){
    bool list[42] = { false };

    int count = 0;
    for ( int i = 0 ; i < 10 ; ++i ){
        int temp;
        scanf("%d", &temp);
        if ( !list[temp % 42] ){
            list[temp % 42] = true;
            ++count;
        }
    }
    printf("%d", count);
    return 0;
}