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
int ret;
int tmp;
deque<int> dq;
vector<int> v;

void solve(int target) {

	int std = dq.size() / 2;
	int where = 0;
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == target)  where = i;
	}
	//cout << "target : " << target << '\n';
	if (where <= std) {
		while (dq.front() != target) {
			dq.push_back(dq.front());
			dq.pop_front();
			ret++;
		}
		//cout << "pop : " << dq.front() << '\n';
		dq.pop_front();
	}
	else {
		while (1) {
			dq.push_front(dq.back());
			dq.pop_back();
			ret++;
			if (dq.front() == target) break;
		}
		dq.pop_front();
	}

	//for (auto i : dq) cout << i << " ";
	//cout << '\n';
}



signed main() {
	fastio;

	cin >> n >> m;

	
	
	for (int i = 0; i < n; i++) {
		dq.push_back(i + 1);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		solve(v[i]);
	}
	
	cout << ret;
}