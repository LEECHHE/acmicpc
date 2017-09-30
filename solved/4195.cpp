#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
map<string, int> friends;
int parent[200005];
int level[200005];
int cnt[200005] = { 0 };
int find(int k) {
	if (k == parent[k]) return parent[k];
	return parent[k] = find(parent[k]);
}

int getIndex(string& s) {
	auto f = friends.find(s);
	if (f == friends.end()) {
		return friends[s] = friends.size();
	}
	return (*f).second;
}

int merge(int a, int b) {
	int s1 = find(a), s2 = find(b);
	if (s1 == s2) {
		return cnt[s1];
	}
	if (level[s1] < level[s2]) {
		swap(s1, s2);
	}

	parent[s2] = s1;
	cnt[s1] += cnt[s2];
	if (level[s1] == level[s2]) ++level[s1];

	return cnt[s1];
}

int main() {
	int n; scanf("%d", &n);
	while(n--) {
		friends.clear();
		int f; scanf("%d", &f);
		for (int i = 0 ; i <= 2 * f ; ++i) {
			parent[i] = i;
			level[i] = 1;
			cnt[i] = 1;
		}
		char n1[21], n2[21];
		for (int i = 0 ; i < f ; ++i) {
			scanf("%s %s", n1, n2);
			string a = n1;
			string b = n2;
			int s1 = getIndex(a);
			int s2 = getIndex(b);
			printf("%d\n", merge(s1, s2));
		}
	}
	return 0;
}
