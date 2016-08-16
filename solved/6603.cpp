#include <cstdio>
#include <vector>
using namespace std;
vector<int> numbers;
vector<int> lotto;
int n;
void print(){
    for( int i = 0 ; i < 6 ; ++i ){
        printf("%d ", lotto[i]);
    }
    printf("\n");
}
void dfs(int curIdx){
    lotto.push_back(numbers[curIdx]);
    if( lotto.size() == 6 ){
        print();
        lotto.erase(lotto.end()-1);
        return;
    }
    for( int i = curIdx + 1 ; i < n ; ++i ){
        dfs(i);
    }
    lotto.erase(lotto.end()-1);
}

int main(){
    while(1){
        scanf("%d",&n);
        if( n == 0 ) break;
        numbers.clear();
        lotto.clear();
        for( int i = 0 ; i < n ; ++i ){
            int t; scanf("%d",&t);
            numbers.push_back(t);
        }
        for( int i = 0 ; i <= n - 6 ; ++i ){
            dfs(i);
        }
        printf("\n");
    }
    return 0;
}