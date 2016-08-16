#include <cstdio>
using namespace std;

int main(){
    char dbt[5] = { 'D', 'C', 'B', 'A', 'E' };
    for ( int j = 0 ; j < 3 ; j++ ){
        int index = 0;
        for ( int i = 0 ; i < 4; i++ ){
            int temp;
            scanf("%d", &temp);
            index += temp;
        }
        printf("%c\n", dbt[index] );
    }
}