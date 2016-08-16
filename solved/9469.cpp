#include <cstdio>
using namespace std;
int main(){
    int P;
    scanf("%d", &P);
    while(P--){
        int N; double D,A,B,F;
        scanf("%d%lf%lf%lf%lf",&N,&D,&A,&B,&F);
        printf("%d %.2lf\n", N, D/(A+B)*F);
    }
    return 0;
}