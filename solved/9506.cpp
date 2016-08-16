#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> yaksu;
int main()
{
    while(1){
        int N; scanf("%d", &N);
        yaksu.erase(yaksu.begin(), yaksu.end());
        if (N<0) break;
        for( int i = 1 ; i <= sqrt(N) ; ++i )
            if( N % i == 0 ) yaksu.push_back(i);
        int result = 1;
        vector<int> temp = yaksu;
        for ( auto it = temp.end()-1; it >= temp.begin()+1; it-- ){
            if ((*it) != 0 ){
                yaksu.push_back(N/(*it));
                result += (*it) + N/(*it);
            }
        }
        if ( result == N ){
            printf("%d = ", N);
            for ( auto it = yaksu.begin(); it != yaksu.end()-1 ; it++ ){
                printf("%d + ", (*it));
            }
            printf("%d\n",yaksu.back());
        }
        else
            printf("%d is NOT perfect.\n", N);
    }
}