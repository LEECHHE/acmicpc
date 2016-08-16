#include <cstdio>
using namespace std;

double price[5] = { 350.34 , 230.90 , 190.55 , 125.30 , 180.90 };
int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
        double sum = 0.0;
        for ( int i = 0 ; i < 5 ; i++ ){
            double temp;
            scanf("%lf", &temp );
            sum += temp * price[i];
        }
        printf("$%.2lf\n", sum);
    }
    return 0;
}