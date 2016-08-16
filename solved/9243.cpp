#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
    int N;
    char list[2][1001];
    
    scanf("%d", &N);
    scanf("%s %s", list[0], list[1]);
    if( N % 2 ){
        int result;
        for( int i = 0 ; i < strlen(list[0]) ; ++i ){
            result += (list[0][i] == list[1][i]);
            if(result > 0){
                printf("Deletion failed\n");
                break;
            }
        }
        if(!result)
            printf("Deletion succeeded\n");
    }
    else{
        if(!strcmp( list[0], list[1] )){
            printf("Deletion succeeded\n");
        }
        else{
            printf("Deletion failed\n");
        }
    }
    return 0;
}