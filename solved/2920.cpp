#include <cstdio>
using namespace std;

int main()
{
    int note, i;
    scanf("%d", &note);
    bool ascend = note == 1? true : false;
    for( i = 1; i < 8 ; ++i ){
        int before = note;
        scanf("%d", &note);
        if ( ascend ){
            if ( before >= note ) break;
        }
        else{
            if ( before <= note ) break;
        }
    }
    if ( i < 8 ) printf("mixed");
    else if ( ascend ) printf("ascending");
    else printf("descending");
    return 0;
}