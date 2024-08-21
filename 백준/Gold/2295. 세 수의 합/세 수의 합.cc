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
vector<int> u;
int tot;
int tmp;
int ret = -1e9;

set<int> s;


signed main() {
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		u.push_back(tmp);
	}

	sort(u.begin(), u.end());
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp = u[i] + u[j];
			s.insert(tmp);
		}
	}

	vector<int> twosum(s.begin(), s.end());
	sort(twosum.begin(), twosum.end());


	int l = 0;
	int r = twosum.size() - 1;

	
	for (int i = u.size() - 1; i >= 0; i--) {
		for (int j = u.size()-1; j >= 0; j--) {

			int l = 0;
			int r = twosum.size() - 1;

			while (l <= r) {

				int mid = (l + r) / 2;

				if (u[i] - u[j] > twosum[mid]) {
					l = mid + 1;
				}
				else if (u[i] - u[j] < twosum[mid]) {
					r = mid - 1;
				}
				else {
					cout << u[i];
					return 0;
				}

			}

		}
	}

	



	return 0;
}

