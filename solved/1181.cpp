#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>    //priority queue
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <map>
using namespace std;

vector< priority_queue<string, vector<string>, greater<string> > > words;
int main(){
    int n; scanf("%d", &n);
    words = vector< priority_queue<string, vector<string>, greater<string> > >( 50, priority_queue<string, vector<string>, greater<string> >() );
    for( int i = 0 ; i < n ; ++i ){
        string word; cin >> word;
        words[word.length()-1].push(word);
    }
    string before = "";
    for( int len = 0 ; len < 50 ; ++len ){
        while(!words[len].empty()){
            if( before.compare(words[len].top()) )
                cout << words[len].top() << endl;
            before = words[len].top();
            words[len].pop();
        }
    }
    return 0;
}