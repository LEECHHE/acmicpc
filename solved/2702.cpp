#include <cstdio>
using namespace std;
 
int gcd( int a , int b ){
    int t;
    while ( b > 0 ){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    int N; scanf("%d", &N);
    while(N--){
    	int a, b;
   		scanf("%d %d", &a, &b);
     
    	printf("%d %d\n", a*b/gcd(a,b), gcd(a,b));
    }
    return 0;
}