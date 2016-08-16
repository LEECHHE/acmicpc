#include <cstdio>
#include <vector>
using namespace std;
vector<int> tri;
bool two[1001] = { false };
bool isTriangle[1001] = { false };
int main(){
    tri.push_back(1);
    for( int i = 2 ; ; ++i ){
        tri.push_back(tri.back()+i);
        if( tri.back() > 1000 ){
            tri.pop_back();
            break;
        }
    }
    for( int i = 0 ; i < tri.size() ; ++i ){
        for( int j = 0 ; j < tri.size() ; ++j ){
            int sum2 = tri[i]+tri[j];
            if( sum2 <= 1000 ){
                two[sum2] = true;
            }
        }
    }
    for( int i = 2 ; i <= 1000 ; ++i ){
        if( two[i] ){
            for( auto t : tri ){
                if( i+t > 1000) break;
                isTriangle[i+t] = true;
            }
        }
    }
    int n; scanf("%d",&n);
    while (n--) {
        int k; scanf("%d",&k);
        printf("%d\n", isTriangle[k]);
    }
    return 0;
}