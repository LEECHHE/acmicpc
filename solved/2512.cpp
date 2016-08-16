#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
    int n; scanf("%d",&n);
    vector<int> require;
    int sum = 0;
    for( int i = 0 ; i < n ; ++i ){
        int t; scanf("%d",&t);
        require.push_back(t);
        sum += t;
    }
    sort(require.begin(), require.end());
    int budget; scanf("%d", &budget);
    int largest = 0;
    if( budget >= sum ){
        largest = require[n-1];
    }
    else{
        if( budget > *(require.begin()) * n ){
            budget -= *(require.begin()) * n;
            largest += *require.begin();
            int idx = 1;
            for( ; require[idx] == require[0] ; ++idx );
            
            while(idx<n){
                int additional = require[idx]-require[idx-1];
                if( budget >= additional * (n-idx)){
                    budget -= additional * (n-idx);
                    largest += additional;
                    for( int next = idx+1; next < n ; ++next ){
                        if( require[next] > require[idx] ){
                            idx = next;
                            break;
                        }
                    }
                }
                else {
                    largest += budget / (n-idx);
                    break;
                }
            }
        }
        else{
            largest = budget / n;
        }
    }
    printf("%d", largest);
    return 0;
}