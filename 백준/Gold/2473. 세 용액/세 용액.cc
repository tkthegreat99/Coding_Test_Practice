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


vector<int> v;
int tmp;
vector<int> ret = { 0, 0, 0 };
int stad = 1e10;


signed main() {
	fastio;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			
			tmp = v[i] + v[j];

			int l = j + 1;
			int r = n - 1;

			while (l <= r) {
				
				int mid = (l + r) / 2;

				if (tmp + v[mid] > 0) {
					r = mid - 1;
					if (abs(tmp + v[mid]) < stad) {
						stad = abs(tmp + v[mid]);
						ret[0] = v[i];
						ret[1] = v[j];
						ret[2] = v[mid];
					}
				}

				else if (tmp + v[mid] < 0) {
					l = mid + 1;
					if (abs(tmp + v[mid]) < stad) {
						stad = abs(tmp + v[mid]);
						ret[0] = v[i];
						ret[1] = v[j];
						ret[2] = v[mid];
					}
				}
				else {
					ret[0] = v[i];
					ret[1] = v[j];
					ret[2] = v[mid];
					sort(ret.begin(), ret.end());
					for (auto k : ret) cout << k << " ";
					return 0;
				}
			}
		}
	}

	sort(ret.begin(), ret.end());
	for (auto k : ret) cout << k << " ";



	
	return 0;
}

