#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> A;
int n;
vector<vector<int>> ret;
vector<vector<int>> temp;
vector<vector<int>>& p2(vector<vector<int>>& mat){
    copy(mat.begin(), mat.end(), temp.begin());
    for( int i = 0; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            mat[i][j] = 0;
            for( int k = 0 ; k < n ; ++k ){
                mat[i][j] += temp[i][k]*temp[k][j];
                mat[i][j] %= 1000;
            }
        }
    }
    return mat;
}
vector<vector<int>>& multi(vector<vector<int>>& a){
    copy(a.begin(), a.end(), temp.begin());
    for( int i = 0; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            a[i][j] = 0;
            for( int k = 0 ; k < n ; ++k ){
                a[i][j] += temp[i][k]*A[k][j];
                a[i][j] %= 1000;
            }
        }
    }
    return a;
}
vector<vector<int>>& decompose(long long N){
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
    scanf("%d",&n);
    long long b; scanf("%lld",&b);
    A = vector<vector<int>>(n, vector<int>(n));
    temp = vector<vector<int>>(n, vector<int>(n));
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < n ; ++j ){
            scanf("%d",&A[i][j]);
        }
    }
    ret = decompose(b);
    for( auto row : ret ){
        for( auto col : row ){
            printf("%d ",col);
        }
        printf("\n");
    }
    return 0;
}