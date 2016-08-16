#include <iostream>
using namespace std;

int count_0, count_1;
void fib(int n){
    if(n==0)
        count_0++;
    else if(n==1)
        count_1++;
    else{
        fib(n-1);
        fib(n-2);
    }
}
int main(){
    
    int n;
    int fib_n;
    cin >> n;
    
    while(n--){
        count_0 = count_1 = 0;
        cin >> fib_n;
        fib(fib_n);
        
        cout << count_0 << " " << count_1 << endl;
    }
    
    return 0;
}