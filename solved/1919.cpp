#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int alphabet[2][26] = { {0},{0} };
int main(){
    for( int j = 0 ; j < 2 ; ++j ){
        char temp[1001]; scanf("%s", temp);
        for ( int i = 0 ; i < strlen(temp) ; ++i )
            alphabet[j][temp[i]-'a']++;
    }
    int result = 0;
    for ( int i = 0 ; i < 26 ; ++i )
        result += abs(double(alphabet[1][i]-alphabet[0][i]));
    printf("%d", result);
    return 0;
}