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
#include <math.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
int budget;
vector<int> v;
int ret = -1e10;


int CanGive(int price) {

	int tot = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] <= price) {
			tot += v[i];
		}
		else tot += price;
	}

	if (tot <= budget) {
		return 1;
	}
	else return 0;
}

signed main() {
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> budget;
		v.push_back(budget);
	}
	cin >> budget;
	sort(v.begin(), v.end());

	int l = 0;
	int r = v[n - 1];

	while (l <= r) {

		int mid = (l + r) / 2;
		int flag = CanGive(mid);

		if (flag) {
			l = mid + 1;
			ret = max(mid, ret);
		}
		else r = mid - 1;
	}

	cout << ret << '\n';
	
	return 0;
}

