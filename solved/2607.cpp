#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int result = 0;
    char first[26] = { 0 };
    int n; scanf("%d", &n);
    char temp[11]; scanf("%s", temp);
    for( int i = 0 ; i < strlen(temp) ; ++i )
        ++first[temp[i]-'A'];
    while(--n){
        char comp[26] = { 0 };
        scanf("%s", temp);
        for( int i = 0 ; i < strlen(temp); ++i ){
            ++comp[temp[i]-'A'];
        }
        for ( int i = 0 ; i < 26; ++i ) comp[i] -= first[i];
        int replaced = 0;
        int omitted = 0;
        for ( int i = 0 ; i < 26; ++i ){
            if ( comp[i] > 0 ) replaced += comp[i];
            else if ( comp[i] < 0 ) omitted -= comp[i];
        }
        if( replaced == 1 && omitted == 1 )
            ++result;
        else if( replaced == 1 && omitted == 0 )
            ++result;
        else if( replaced == 0 && omitted == 1 )
            ++result;
        else if ( replaced == 0 && omitted == 0 )
            ++result;
    }
    printf("%d", result);
    return 0;
}