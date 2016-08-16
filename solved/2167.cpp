#include <iostream>
using namespace std;

int arr[300][300];

int main(){
    int N, M;
    int K;
    
    cin >> N >> M;

    for( int i = 0; i < N ; i++){
        for( int j = 0; j < M ; j++){
            cin >> arr[i][j];
        }
    }

    cin >> K;

    int i, j, x, y;
    int sum;
    while(K--){
        sum = 0;
        cin >> i >> j >> x >> y;
        for(int row = i-1 ; row <= x-1; row++){
            for(int col = j-1 ; col <= y-1 ; col++)
                sum += arr[row][col];
        }
        cout << sum << endl;
    }
    return 0;
}