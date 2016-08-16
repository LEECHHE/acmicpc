#include <cstdio>
using namespace std;

int main () {
    int T, N;
    scanf("%d", &T);
    
    while(T--){
        int result = 0;
        scanf("%d", &N);
        while(N--){
            int temp;
            scanf("%d", &temp);
            result += temp;
        }
        printf("%d\n", result);
    }
    return 0;
}