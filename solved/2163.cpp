#include <cstdio>
using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    
    printf("%d", (M-1) + M * (N-1));
    
    return 0;
}