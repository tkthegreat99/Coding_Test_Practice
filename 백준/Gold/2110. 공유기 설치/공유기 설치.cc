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

int n, c;
vector<int> v;
int tmp;
int ret = -1;

int IsPossible(int d) {
	int cnt = 1;
	
	tmp = v[0];

	for (int i = 1; i < n; i++) {
		if(v[i] - tmp>= d){
			cnt++;
			tmp = v[i];
		}
		if (cnt == c) {
			return 1;
		}
	}

	return 0;
}


signed main() {
	fastio;

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());

	int l = 0;
	int r = v[n - 1] - v[0];

	while (l <= r) {

		int mid = (l + r) / 2;

		int flag = IsPossible(mid);

		if (flag) {
			ret = max(ret, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ret << '\n';
	return 0;
}
//GardenPrettiest
