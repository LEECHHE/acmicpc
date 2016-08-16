#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    
    int min = ceil(sqrt(M));
    int max = floor(sqrt(N));
    int sum = 0;
    
    if( min > max ){
        cout << -1 << endl;
        return 0;
    }
    for (int i = min ; i <= max ; i++)
        sum += i*i;
    
    cout << sum << endl;
    cout << min*min << endl;
    return 0;
}