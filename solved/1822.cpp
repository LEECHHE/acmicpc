#include <cstdio>
#include <map>
using namespace std;

int main () {
    int nA, nB;
    scanf ( "%d %d", &nA, &nB );
    int count = nA;
    map <int, bool> setA;
    while( nA-- ){
        int temp;
        scanf("%d", &temp);
        setA.insert( pair< int, bool >( temp, 0 ) );
    }
    while ( nB -- ){
        int temp;
        scanf("%d", &temp );
        auto it = setA.find ( temp );
        if ( it != setA.end()){
            setA.erase( it );
            --count;
        }
    }
    if ( !count )
        printf("0");
    else{
        printf("%d\n", count);
        for ( auto& x : setA ){
            printf( "%d ", x.first );
        }
    }

    return 0;
}