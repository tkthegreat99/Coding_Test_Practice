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
/* Jeongwon Is Cute And "P.R.E.T.T.Y"  */

int n, m;
vector<int> v;
int tmp;
vector<int> v2;




signed main() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	
	for (int i = 0; i < m; i++) {
		v2.push_back(0);
	}
	for (int i = 0; i < n - m; i++) {
		v2.push_back(1);
	}

	sort(v.begin(), v.end());

	do{
		for (int i = 0; i < n; i++) {
			if (!v2[i]) cout << v[i] << " ";
		}
		cout << '\n';
	}while(next_permutation(v2.begin(), v2.end()));

	return 0;
}