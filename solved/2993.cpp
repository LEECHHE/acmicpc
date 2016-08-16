#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    char s[51]; scanf("%s", s);
    string word(s);
    priority_queue<string, vector<string>, greater<string>> pq;
    for( int i = 1 ; i < word.length()-1; ++i ){
        for( int j = i+1 ; j < word.length() ; ++j ){
            string temp(word);
            reverse(temp.begin(), temp.begin()+i);
            reverse(temp.begin()+i, temp.begin()+j);
            reverse(temp.begin()+j, temp.end());
            pq.push(temp);
        }
    }
    printf("%s", pq.top().c_str());
    return 0;
}