#include <cstdio>
#include <vector>
using namespace std;

vector<int> people;
int main(){
    int n; int taller[10];
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i += scanf("%d", &taller[i]) );
    for ( int i = n-1 ; i >= 0 ; --i ){
        people.insert(people.begin()+taller[i], i+1);
    }
    for( auto height : people ) printf("%d ", height);
    return 0;
}