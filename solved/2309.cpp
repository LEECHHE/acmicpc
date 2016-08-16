#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> dwarf;
    int sum = 0;
    for ( int i = 0 ; i < 9 ; ++i ){
        int temp;
        scanf( "%d", &temp );
        dwarf.push_back(temp);
        sum += temp;
    }
    for ( int i=0 ; i < 8 ; ++i ){
        for ( int j = i+1 ; j < 9 ; ++j ){
            if ( sum - (dwarf.at(i) + dwarf.at(j)) == 100 ){
                dwarf.erase(dwarf.begin()+j);
                dwarf.erase(dwarf.begin()+i);
                break;
            }
        }
        if ( dwarf.size() == 7 )
              break;
    }
    sort( dwarf.begin(), dwarf.end() );
    for( auto it = dwarf.begin() ; it != dwarf.end() ; ++it )
        printf( "%d\n", *it );
    
    return 0;
}