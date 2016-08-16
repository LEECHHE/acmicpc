#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n % 7 == 2 || n % 7 == 0) printf("CY");
    else printf("SK");
    return 0;
}