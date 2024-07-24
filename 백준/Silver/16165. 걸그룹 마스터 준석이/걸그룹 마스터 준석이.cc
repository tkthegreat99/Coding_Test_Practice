#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <limits.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
map<string, string> mp1;
map<string, string> mp2;

string ggname;
int num;
string name;




signed main() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ggname;

		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> name;
			mp1[name] = ggname;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		cin >> num;
		if (num == 0) {
			for (auto j : mp1) {
				if (j.second == name) cout << j.first << '\n';
			}
		}
		else {
			for (auto j : mp1) {
				if (j.first == name) cout << j.second << '\n';
			}
		}
	}
	
	return 0;
	
}