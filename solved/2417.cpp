#include<cstdio>
#include<cmath>
using namespace std;
    
    int main(){
        unsigned long long a;
        scanf("%llu", &a);
        printf("%llu", (unsigned long long)ceil(sqrt((double)a)));
        return 0;
    }