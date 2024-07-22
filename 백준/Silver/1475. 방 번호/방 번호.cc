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

string n;
int mx = -1e9;
map<int, int> mp;
int tmp, ret;

signed main() {
	fastio;

	cin >> n;

	for (int i = 0; i < n.length(); i++) {
		mp[n[i] - '0']++;
	}

	for (auto k : mp) {
		if (k.first == 6 || k.first == 9) {
			tmp += k.second;
		}
		else {
			mx = max(mx, k.second);
		}
	}

	if (tmp % 2 == 0) tmp /= 2;
	else tmp = (int)(tmp / 2) + 1;

	ret = max(tmp, mx);

	cout << ret;
	return 0;
}