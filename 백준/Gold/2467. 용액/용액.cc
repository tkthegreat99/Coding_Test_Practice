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
vector<int> ret = { 0, 0};
int stad = 1e10;
int n;


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

		while (l <= r) {

			int mid = (l + r) / 2;

			if (v[i] + v[mid] > 0) {
				r = mid - 1;
				if (abs(v[i] + v[mid]) < stad) { 
					stad = abs(v[i] + v[mid]); 
					ret[0] = v[i];
					ret[1] = v[mid];
				}
			}

			else if (v[i] + v[mid] < 0) {
				l = mid + 1;
				if (abs(v[i] + v[mid]) < stad) {
					stad = abs(v[i] + v[mid]);
					ret[0] = v[i];
					ret[1] = v[mid];
				}
			}

			else {
				ret[0] = v[i];
				ret[1] = v[mid];
				sort(ret.begin(), ret.end());
				for (auto k : ret) cout << k << " ";
				return 0;

			}
		}
	}
	//cout << ret.size() << '\n';
	sort(ret.begin(), ret.end());
	for (auto k : ret) cout << k << " ";


	
	return 0;
    //Garden6482 is Pretty
}

