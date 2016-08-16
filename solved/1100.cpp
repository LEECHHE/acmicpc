#include <cstdio>
using namespace std;

int main(){
    bool column_even = true;
    bool row_even = true;
    int count = 0;
    
    for ( int i = 0 ; i < 8 ; i++ ){
        char temp[9];
        scanf("%s", temp);
        for ( int j = 0 ; j < 8 ; j++ ){
            if ( temp[j] == 'F' ){
                if ( column_even && row_even )
                    count++;
                else if ( !column_even && !row_even )
                    count++;
            }
            column_even = !column_even;
        }
        row_even = !row_even;
    }
    printf("%d", count);
    return 0;
}