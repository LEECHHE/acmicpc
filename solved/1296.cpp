#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string ret;
int org[4]={0};
int get_score(string name){
	int cnt[4] = { 0 };
	for( int i = 0 ; i < name.length() ; ++i ){
		if( name[i] == 'L' ) ++cnt[0];
		else if(name[i] == 'O') ++cnt[1];
		else if(name[i] == 'V') ++cnt[2];
		else if(name[i] == 'E') ++cnt[3];
	}
	return (((org[0]+cnt[0]+org[1]+cnt[1])*(org[0]+cnt[0]+org[2]+cnt[2])*(org[0]+cnt[0]+org[3]+cnt[3]))%100)*(((org[1]+cnt[1]+org[2]+cnt[2])*(org[1]+cnt[1]+org[3]+cnt[3])*(org[2]+cnt[2]+org[3]+cnt[3]))%100)%100;
}
int main(){
	char name[25]; scanf("%s", name);
	for( int i = 0 ; i < strlen(name) ; ++i ){
		if( name[i] == 'L' ) ++org[0];
		else if(name[i] == 'O') ++org[1];
		else if(name[i] == 'V') ++org[2];
		else if(name[i] == 'E') ++org[3];
	}

	int n; scanf("%d",&n);
	int cnt[4];
	int max_score = -1;
	vector<string> ret;
	for( int i = 0 ; i < n ; ++i ){
		string ss; cin >> ss;
		int cur_score = get_score(ss);
		if( max_score <	cur_score ){
			ret.clear();
			ret.push_back(ss);
			max_score = cur_score;
		}
		else if( max_score == cur_score ) ret.push_back(ss);
	}
	sort(ret.begin(), ret.end());
	cout << ret[0];
	return 0;
}