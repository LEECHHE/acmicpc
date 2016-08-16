#include <cstdio>
using namespace std;

bool seat[100] = { false };
int main(){
    int N;
    scanf("%d", &N);
    
    int count = 0;
    while(N--){
        int temp;
        scanf( "%d", &temp );
        if ( seat[temp-1] ) ++count;
        else seat[temp-1] = true;
    }
    printf("%d", count);
    return 0;
}