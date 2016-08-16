#include <vector>
#include <string>
#include <map>

using namespace std;

string names[100000];
map <string, int> _hash;

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		char temp[21];
		scanf("%s", temp);
		names[i] = temp;
		_hash[names[i]] = i;
	}

	for(int i = 0; i < m; i++)
	{
		char temp[21];
		scanf("%s", temp);
		if(temp[0] <= '9') printf("%s\n", names[stoi(temp) - 1].c_str());
		else printf("%d\n", _hash[temp] + 1);
	}

	return 0;
}