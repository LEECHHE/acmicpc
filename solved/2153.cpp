#include <cstdio>
using namespace std;
bool notPrime[2000] = { false };
int main(){
    char word[21]; scanf("%s", word);
    for( int i = 2 ; i < 2000 ; ++i ){
        if(!notPrime[i]){
            for( int j = i*2 ; j < 2000 ; j += i ){
                notPrime[j] = true;
            }
        }
    }
    notPrime[0] = true;
    int res = 0;
    for( int i = 0 ; word[i] != '\0' ; ++i ){
        if( word[i] >= 'a' ){
            word[i] -= 'a'-1;
        }
        else{
            word[i] -= 'A'-1;
        }
        res += word[i];
    }
    printf("It is ");
    if( notPrime[res] ) printf("not ");
    printf("a prime word.");
    return 0;
}