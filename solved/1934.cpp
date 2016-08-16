#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a; int b;
    scanf("%d", &n);
    
    while(n--){
        scanf("%d %d", &a, &b);
        int gcd_a = a;
        int gcd_b = b;
       
        if( gcd_a > gcd_b )
            swap(gcd_a, gcd_b);
        while ( (gcd_b % gcd_a) != 0 ){
            gcd_b %= gcd_a;
            
            if( gcd_a > gcd_b )
                swap(gcd_a, gcd_b);
        }
        
        printf("%d\n", a * b / gcd_a );
        
    }
    
    return 0;
}