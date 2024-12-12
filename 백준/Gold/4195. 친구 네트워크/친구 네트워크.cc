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
#include <deque>
#include <sstream>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define INF 987654321

using namespace std;

int n, m, k;
unordered_map<string, string> um;
unordered_map<string, int> nums;


string find(string a) {
	if (um[a] == a) {
		return a;
	}
	else {
		return um[a] = find(um[a]);
	}
}

void uni(string a, string b) {
	string A = find(a);
	string B = find(b);

	if (A == B) return;

	um[B] = A;
	nums[A] += nums[B];
}

signed main()
{

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tn;
	cin >> tn;

	while (tn--) {
		int n;
		cin >> n;

		um.clear();
		nums.clear();

		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (um.count(a) == 0) {
				um.insert(make_pair(a, a));
				nums.insert(make_pair(a, 1));
			}
			if (um.count(b) == 0) {
				um.insert(make_pair(b, b));
				nums.insert(make_pair(b, 1));
			}
			uni(a, b);
			cout << nums[find(a)] << '\n';

		}
	}

}