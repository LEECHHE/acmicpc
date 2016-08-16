#include <map>
#include <cstdio>
using namespace std;

int main(){
    map<int, int> input;
    int N; int M;
    int temp;
    
    scanf("%d", &N);
    for( int i = 0 ; i < N ; i++ ){
        scanf("%d", &temp);
        input.insert({temp, i});
    }
    
    scanf("%d", &M);
    map<int, int>::iterator it;
    for( int i = 0 ; i < M ; i++ ){
        scanf("%d", &temp);
        it = input.find(temp);
        if( it != input.end() )
            printf("1\n");
        else
            printf("0\n");
    }
    
    return 0;
}