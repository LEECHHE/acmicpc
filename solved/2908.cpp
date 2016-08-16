#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
    char input[2][4];
    scanf("%s %s", input[0], input[1] );
    char temp = input[0][0];
    input[0][0] = input[0][2];
    input[0][2] = temp;
    
    temp = input[1][0];
    input[1][0] = input[1][2];
    input[1][2] = temp;
    
    int compare[2];
    compare[0] = atoi( input[0] );
    compare[1] = atoi( input[1] );
    
    printf("%d", max( compare[0], compare[1] ) );
    return 0;
    
}