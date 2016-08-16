#include <cstdio>
using namespace std;

int main(){
    int remainder_list[10][4] = {
        { 10, 10, 10, 10 },
        { 1, 1, 1, 1 },
        { 6, 2, 4, 8 },
        { 1, 3, 9, 7 },
        { 6, 4, 6, 4 },
        { 5, 5, 5, 5 },
        { 6, 6, 6, 6 },
        { 1, 7, 9, 3 },
        { 6, 8, 4, 2 },
        { 1, 9, 1, 9 } };
    
    int T;
    int a; int b;
    
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &a, &b);
        printf("%d\n", remainder_list[a % 10][b % 4]);
    }
    
    return 0;
}