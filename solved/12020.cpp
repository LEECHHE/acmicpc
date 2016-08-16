#include<iostream>
using namespace std;
int n;
double A[1001][1001] = { 0 };
double c[1001];
double a[1001];
double b[1001];

bool solve(int x, int y){
    if( x == n+1 ) return true;
    if( x == y ){
        a[x] = A[x][y]-b[x-1]*c[x-1];
        return solve(x+1,y);
    }
    else if( x == y+1 ){
        if( a[y] <= 0.000000001 && a[y] >= -0.000000001 ) return false;
        b[y] = A[x][y]/a[y];
        return solve(x,y+1);
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            scanf("%lf",&A[i][j]);
        }
    }
    for( int i = 1 ; i <= n-1 ; ++i ){
        c[i] = A[i][i+1];
    }
    if(!solve(1,1)){
        printf("-1");
    }
    else{
        //L
        printf("1.000");
        for( int i = 1 ; i <= n ; ++i ){
            //print 0
            for( int j = 2 ; j < i ; ++j ){
                printf("0.000 ");
            }
            if( i >= 2 ){
                printf("%.3lf 1.000",b[i-1]);
            }
            for( int j = i+1 ; j <= n ; ++j ){
                printf(" 0.000");
            }
            printf("\n");
        }
        
        //U
        for( int i = 1 ; i <= n ; ++i ){
            //print 0
            for( int j = 1 ; j < i ; ++j ){
                printf("0.000 ");
            }
            if( i < n )
                printf("%.3lf %.3lf",a[i],c[i]);
            else
                printf("%.3lf",a[i]);
            
            for( int j = i+2 ; j <= n ; ++j ){
                printf(" 0.000");
            }
            printf("\n");
        }
    }
    return 0;
}