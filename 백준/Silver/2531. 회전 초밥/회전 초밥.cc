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

int n, d, k, c, tmp;
int cnt;
int sushi[3000];
int dish[30000];
map<int, int> m;
int ret = -1e9;

signed main() {
	fastio;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dish[i] = tmp;
	}


	for (int i = 0; i < k; i++) {
		m[dish[i]]++;
		if (m[dish[i]] == 1) cnt++;
	}
	int s = 0;
	int e = k;

	ret = max(ret, cnt);
	

	while (s < n) {
		m[dish[s]]--;
		if (m[dish[s]] == 0) cnt--;
		m[dish[e]]++;
		if (m[dish[e]] == 1) cnt++;
		
		s++;
		e++;
		e %= n;
		if (m[c] == 0) {
			ret = max(ret, cnt + 1);
		}
		else ret = max(ret, cnt);
	}

	cout << ret << '\n';
}
