#include <cstdio>
#include <vector>
using namespace std;

vector<int> people;
int main(){
    int n, m; scanf("%d%d",&n,&m);
    for( int i = 1; i <= n ; ++i ) people.push_back(i);
    int current = m-1;
    printf("<");
    for( int i = 0 ; i < n-1 ; ++i ){
        printf("%d, ",people[current]);
        people.erase(people.begin()+current);
        current = (current+m-1)%people.size();
    }
    printf("%d>",people[0]);
    return 0;
}