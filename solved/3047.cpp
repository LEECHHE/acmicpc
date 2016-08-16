#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int list[3];
    scanf("%d %d %d", &list[0], &list[1], &list[2] );
    sort ( list, list + 3 );
    char order[4];
    scanf( "%s", order );
    
    printf("%d %d %d", list[order[0] - 'A'], list[order[1] -'A'], list[order[2] - 'A'] );
    return 0;
}