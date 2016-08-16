#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double diagonal;
    double width, height;
    scanf("%lf %lf %lf", &diagonal, &width, &height);
    printf("%d %d", (int)floor((sqrt(diagonal * diagonal / ((width*width) + (height*height))) * width)), (int)floor((sqrt(diagonal * diagonal / ((width*width) + (height*height))) * height)));
    return 0;
}