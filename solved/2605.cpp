#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector<int> student;
    int the_number_of_student;
    int current_number = 1;
    scanf( "%d", &the_number_of_student );
    while(the_number_of_student--)
    {
        int lotto;
        scanf( "%d", &lotto );
        student.insert( student.begin() + current_number - lotto - 1 , current_number );
        ++current_number;
    }
    for ( auto it = student.begin() ; it != student.end() ; ++it )
        printf( "%d ", *it );
    return 0;
}