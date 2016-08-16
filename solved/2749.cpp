#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
vector<vector<long long>> A;
vector<vector<long long>> ret;
vector<vector<long long>> temp;
vector<vector<long long>>& p2(vector<vector<long long>>& mat){
    copy(mat.begin(), mat.end(), temp.begin());
    for( int i = 0; i < 2 ; ++i ){
        for( int j = 0 ; j < 2 ; ++j ){
            mat[i][j] = 0;
            for( int k = 0 ; k < 2 ; ++k ){
                mat[i][j] += temp[i][k]*temp[k][j];
                mat[i][j] %= 1000000;
            }
        }
    }
    return mat;
}
vector<vector<long long>>& multi(vector<vector<long long>>& a){
    copy(a.begin(), a.end(), temp.begin());
    for( int i = 0; i < 2 ; ++i ){
        for( int j = 0 ; j < 2 ; ++j ){
            a[i][j] = 0;
            for( int k = 0 ; k < 2 ; ++k ){
                a[i][j] += temp[i][k]*A[k][j];
                a[i][j] %= 1000000;
            }
        }
    }
    return a;
}
vector<vector<long long>>& decompose(long long N){
    if( N == 1 ) return A;
    if( N % 2 == 0 ){
        ret = decompose(N/2);
        return p2(ret);
    }
    else{
        return multi(decompose(N-1));
    }
}
int main(){
    long long b; scanf("%lld",&b);
    if( b < 2 ){
        printf("%lld", b);
        return 0;
    }
    A = vector<vector<long long>>(2, vector<long long>(2));
    temp = vector<vector<long long>>(2, vector<long long>(2));
    A[0][0] = 1; A[0][1] = 1; A[1][0] = 1; A[1][1] = 2;

    ret = decompose(b/2);
    if( b%2 == 0 )
        printf("%lld", ret[0][1]);
    else
        printf("%lld", ret[1][1]);
    return 0;
}