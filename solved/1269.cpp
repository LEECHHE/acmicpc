#include<cstdio>
using namespace std;
bool A[100000001] = { 0 };
int main(){
    int a,b; scanf("%d%d", &a,&b);
    for( int i = 0 ; i < a ; ++i ){
        int temp; scanf("%d", &temp);
        A[temp] = 1;
    }
    int only_a = a;
    int only_b = 0;
    for ( int i = 0 ; i < b ; ++i ){
        int temp; scanf("%d", &temp);
        if(!A[temp]) ++only_b;
        else --only_a;
    }
    printf("%d", only_a+only_b);
    return 0;
}