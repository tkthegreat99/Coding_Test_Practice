#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int k, l;
string num;
map<string, int> mp;
int cnt = 1;
int cnt2 = 0;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	//if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}


signed main() {
	fastio;

	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		cin >> num;
		mp[num] = cnt;
		cnt++;
	}
	vector<pair<string, int>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);

	int std = min((int)v.size(), k);

	for (int i = 0; i < std; i++) {
		cout << v[i].first << '\n';
	}
	


	return 0;
}

