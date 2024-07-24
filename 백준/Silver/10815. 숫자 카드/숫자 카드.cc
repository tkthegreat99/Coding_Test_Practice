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
int tmp;
vector<int> v;
vector<int> v2;

signed main() {
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int l = 0;
		int r = v.size()-1;
		int mid = (l + r) / 2;
		cin >> tmp;
		int chk = 0;
		while (l <= r) {

			mid = (l + r) / 2;

			//찾으려는 것보다 v[mid] 가 작음. 더 큰데서 찾아야함.
			if (v[mid] < tmp) {
				l = mid + 1;
			}
			else if (v[mid] > tmp) {
				r = mid - 1;
			}
			else if (v[mid] == tmp) {
				chk = 1;
				break;
			}
		}
		cout << chk << " ";
	}
	return 0;
}