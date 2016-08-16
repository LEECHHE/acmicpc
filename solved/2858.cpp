#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int r,b;
    scanf("%d%d",&r,&b);
    int var = sqrt((4-r)*(4-r)-16*b);
    printf("%d %d", (4+r+var)/4, (4+r-var)/4);
    return 0;
}