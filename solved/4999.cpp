#include <cstdio>
#include <cstring>
using namespace std;

int main () {
    char jae[1001];
    char doc[1001];
    
    scanf("%s", jae);
    scanf("%s", doc);
    
    if( strlen(jae) >= strlen(doc))
        printf("go");
    else
        printf("no");
    
    return 0;
}