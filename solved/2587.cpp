#include <cstdio>
#include <cstdlib>
using namespace std;
int compare(const void *a, const void *b){
    return (*(int*)a) < (*(int*)b);
}
int main(){
    int input[5];
    int sum;
    for ( int i = 0 ; i < 5 ; i++ ){
        scanf("%d", &input[i]);
        sum += input[i];
    }
    qsort( input, 5, sizeof(int), compare );
    printf("%d\n%d", sum/5, input[2] );
    return 0;
}