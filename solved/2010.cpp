#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int max = 1;
    while(N--){
        int temp;
        scanf("%d", &temp);
        max = max - 1 + temp;
    }
    printf("%d", max);
    return 0;
}