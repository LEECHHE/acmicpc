#include <cstdio>
using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int result = b-a > c-b ? b-a-1 : c-b-1;
    printf("%d", result);
    return 0;
}