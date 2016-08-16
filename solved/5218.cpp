#include <cstdio>
#include <cstring>
char s1[20], s2[20];
int main(){
    int N; scanf("%d", &N);
    for ( int i  = 0 ; i < N ; ++i ){
        scanf("%s %s", s1, s2);
        printf("Distances: ");
        for ( int j = 0 ; j < strlen(s1) ; ++j ){
            if (s2[j] >= s1[j]) printf("%d ", s2[j]-s1[j]);
            else printf("%d ", 26 + s2[j] - s1[j]);
        }
        printf("\n");
    }
    return 0;
}