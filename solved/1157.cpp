#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char * argv[])
{
    int count[26] = {0};
    string input;
    bool dup = false;
    
    cin >> input;
    
    for(int i=0;i<input.length();i++){
        int ch = input[i]-65;
        if(ch > 25){
            ch -= 32;
        }

        count[ch]++;
    }
    int max = 0;
    for(int i=1; i < 26;i++){
        if( count[max] < count[i] ){
            max = i;
            dup = false;
        }
        else if(count[max] == count[i]){
            dup = true;
        }
        else
            continue;
    }
    if(dup) cout << "?" << endl;
    else cout << (char)(max+65) << endl;
    return 0;
}