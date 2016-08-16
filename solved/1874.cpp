#include <cstdio>
#include <stack>
using namespace std;

stack<char> op;
stack<int> s;
int numbers[100000];

int main(){
    int n; scanf("%d", &n);
    for( int i = n-1 ; i >= 0 ; --i ) scanf("%d", &numbers[i]);
    
    int expected = n;
    int current = 0;
    while(expected > 0){
        while ( s.empty() || s.top() != expected ){
            if( current >= n ) break;
            s.push(numbers[current++]); op.push('-');
        }
        while( !s.empty() && s.top() == expected ){
            s.pop(); op.push('+');
            expected--;
        }
        
        if( current >= n )
            break;
    }
    if( expected == 0 ){
        while(!op.empty()){
            printf("%c\n",op.top());
            op.pop();
        }
    }
    else{
        printf("NO");
    }
    return 0;
}