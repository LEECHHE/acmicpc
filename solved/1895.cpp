#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int img[40][40];
vector<int> filter;
int main(){
    int r,c; scanf("%d %d", &r, &c);
    for( int i = 0 ; i < r ; ++i ){
        for ( int j = 0 ; j < c ; ++j )
            scanf("%d", &img[i][j]);
    }
    int t; scanf("%d", &t);
    int count = 0;
    for( int i = 0 ; i < r-2 ; ++i ){
        for ( int j = 0 ; j < c-2 ; ++j){
            for( int k = i ; k < i+3 ; ++k ){
                for( int l = j ; l < j+3; ++l ){
                    filter.push_back(img[k][l]);
                }
            }
            sort(filter.begin(), filter.end());
            if( filter[4] >= t ) ++count;
            filter.erase(filter.begin(), filter.end());
        }
    }
    printf("%d", count);
    return 0;
}