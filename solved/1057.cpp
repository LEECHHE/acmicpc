#include <cstdio>
using namespace std;
int main(){
    int n, kim, han; scanf("%d%d%d",&n,&kim,&han);
    int ret = 0;
    while (kim != han) {
        kim = (kim+1)/2;
        han = (han+1)/2;
        ++ret;
    }
    printf("%d",ret);
    return 0;
}