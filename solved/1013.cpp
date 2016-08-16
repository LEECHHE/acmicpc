#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n; scanf("%d",&n);
    while(n--){
        char msg[201]; scanf("%s", msg);
        int isPattern = false;
        for(int current = 0 ; current < strlen(msg) ; ){
            isPattern = false;
            if( !strncmp("100", &msg[current], 3)){
                current += 3;
                while(msg[current]=='0') ++current;
                if(msg[current] == '1'){
                    ++current;
                    isPattern = true;
                }
                while(msg[current]=='1'){
                    if(!strncmp("100", &msg[current], 3)) break;
                    ++current;
                }
            }
            else if( !strncmp("01", &msg[current], 2)){
                current += 2;
                isPattern = true;
            }
            else{
                isPattern = false;
                break;
            }
        }
        if( isPattern ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}