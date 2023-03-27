#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;


int n, m;

int test[101];
string s1, s2;


int main() {
	cin >> n;
	while (n--) {
		map<string, int> mp;
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> s1 >> s2;
			mp[s2]++;
		}
		int ret = 1;
		for (auto c : mp) {
			ret *= ((int)c.second + 1);
		}
		ret--;
		cout << ret << '\n';
	}
	return 0;
}

	

