#include <cstdio>
using namespace std;
int main () {
    int A,B,V;
    scanf("%d%d%d",&A,&B,&V);
    int height = 0;
    int day = 0;
    
    if ( V == B ){
        printf("1");
        return 0;
    }
    int mount_per_day = A-B;
    while ( height + A < V ){
        height += mount_per_day;
        day++;
    }
    printf("%d", day + 1);
    return 0;
}