#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main(){
    char name[51]; scanf("%s", name);
    char alpha[28] = { 0 };
    for ( int i = 0 ; i < strlen(name) ; ++i ){
        ++alpha[name[i]-'A'];
    }
    int odd = -1;
    for ( int i = 0 ; i < 28 ; ++i ){
        if(alpha[i]%2){
            if( odd < 0 ) odd = i;
            else{
                printf("I'm Sorry Hansoo");
                return 0;
            }
        }
    }
    for( int i = 0 ; i < 28 ; ++i ){
        for( int j = 0 ; j < alpha[i]/2 ; ++j ){
            printf("%c",'A'+i);
        }
        alpha[i] -= alpha[i]/2;
    }
    if( odd >= 0 ){
        printf("%c", 'A'+odd);
        --alpha[odd];
    }
    for( int i = 27 ; i >= 0 ; --i ){
        for( int j = 0 ; j < alpha[i] ; ++j )
            printf("%c",'A'+i);
    }
    return 0;
}