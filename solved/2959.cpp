#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int line[4]; scanf("%d%d%d%d",&line[0],&line[1],&line[2],&line[3]);
    sort(line, line+4);
    printf("%d", line[0]*line[2]);
    return 0;
}