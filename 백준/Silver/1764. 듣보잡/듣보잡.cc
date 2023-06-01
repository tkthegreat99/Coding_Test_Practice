#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;


int n, m, tmp, tmp2;
vector<string> vt;
map<string, int> ma;


int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		string str;
		cin >> str;
		ma[str]++;
		if (ma[str] > 1) vt.push_back(str);
	}
	sort(vt.begin(), vt.end());
	cout << vt.size() << '\n';
	for (auto k : vt) cout << k << '\n';
}