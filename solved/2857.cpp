#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    char name[11];
    vector<int> ans;
    for( int i =1 ; i <= 5 ; ++i ){
        scanf("%s", name);
        int len = (int)strlen(name);
        for( int j = 0 ; j < len-2 ; ++j ){
            if( name[j] != 'F') continue;
            if( name[j+1] != 'B') continue;
            if( name[j+2] == 'I') ans.push_back(i);
        }
    }
    if(ans.empty()){
        printf("HE GOT AWAY!");
    }
    else{
        for ( auto a : ans ){
            printf("%d ",a);
        }
    }
    return 0;
}