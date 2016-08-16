#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int result = 0;
    for( int i = 0 ; i < n ; ++i ){
        bool isGroup = true;
        bool group[26] = { 0 };
        char word[101]; scanf("%s", word);
        char current = word[0];
        group[word[0]-'a'] = 1;
        for( int i = 1 ; i < strlen(word) ; ++i ){
            if ( current != word[i] ){
                if( !group[word[i]-'a'] ){
                    group[word[i]-'a'] = 1;
                    current = word[i];
                }
                else {
                    isGroup = false;
                    break;
                }
            }
        }
        if( isGroup ) ++result;
    }
    printf("%d", result);
    return 0;
}