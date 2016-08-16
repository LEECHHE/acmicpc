#include <cstdio>
using namespace std;

bool numbers[10000] = { false };
int main(){
    for ( int i = 0 ; i < 10000 ; ++i ){
        int n = i+1;
        int self = n;
        while( self <= 10000 ){
            while( n > 0 ){
                self += n%10;
                n /= 10;
            }
            numbers[self-1] = true;
            n = self;
        }
    }
    for ( int i = 0 ; i < 10000 ; ++i ){
        if(!numbers[i]) printf("%d\n", i+1);
    }
    return 0;
}