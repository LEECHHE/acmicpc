#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int sum = 0;
    int dup = 1;
    while(N--){
        int temp;
        scanf("%d", &temp);
        if ( temp == 1 )
            sum += dup++;
        else
            dup = 1;
    }
    printf("%d", sum);
    return 0;
}