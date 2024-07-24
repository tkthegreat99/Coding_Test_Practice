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

int n;
int tmp;
vector<int> v;
int ret = 200000001;

int plus2(int a, int b) {
	if (abs(a) > abs(b)) return b;
	else return a;
}




signed main() {
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	
	for (int i = 0; i < n; i++) {

		int l = i + 1;
		int r = n - 1;
		int mid = (l + r) / 2;

		while (l <= r) {

			mid = (l + r) / 2;

			if (v[mid] + v[i] > 0) {
				r = mid - 1;
				ret = plus2(ret, v[i] + v[mid]);
			}
			else if (v[mid]  + v[i] < 0) {
				l = mid + 1;
				ret = plus2(ret, v[i] + v[mid]);
			}			
			else {
				cout << 0;
				return 0;
			}

		}

		

	}
	cout << ret;

	return 0;
	
}