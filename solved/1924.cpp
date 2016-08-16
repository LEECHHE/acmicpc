#include <cstdio>
using namespace std;

int main(){
    enum Days { Sun = 0, Mon, Tue, Wed, Thu, Fri, Sat };
    int first_Day[12];
    first_Day[0] = Mon;
    for( int i = 1 ; i < 12 ; i++ ){
        switch ( i + 1 ) {
            case 2:
            case 4:
            case 6:
            case 8:
            case 9:
            case 11:
                first_Day[i] = (first_Day[i-1] + 31 ) % 7;
                break;
            case 3:
                first_Day[i] = ( first_Day[i-1] + 28 ) % 7;
                break;
            case 5:
            case 7:
            case 10:
            case 12:
                first_Day[i] = ( first_Day[i-1] + 30 ) % 7;
                break;
            default:
                break;
        }
    }
    int x, y;
    scanf ("%d %d", &x, &y);
    switch ((first_Day[x-1] + y - 1) % 7) {
        case Mon:
            printf("MON");
            break;
        case Tue:
            printf("TUE");
            break;
        case Wed:
            printf("WED");
            break;
        case Thu:
            printf("THU");
            break;
        case Fri:
            printf("FRI");
            break;
        case Sat:
            printf("SAT");
            break;
        case Sun:
            printf("SUN");
            break;
            
        default:
            break;
    }
    return 0;
}