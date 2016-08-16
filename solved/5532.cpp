#include<cstdio>
using namespace std;
int main(){
 	int L,A,B,C,D; scanf("%d%d%d%d%d", &L,&A,&B,&C,&D);
    int kor = A%C? A/C+1 : A/C;
    int math = B%D? B/D+1 : B/D;
    int result = kor > math? kor : math;
    result = result < 0 ? 0 : result;
    printf("%d", L-result);
    return 0;
}