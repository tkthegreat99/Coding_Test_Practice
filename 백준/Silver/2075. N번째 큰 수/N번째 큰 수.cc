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
//int a[1500][1500];
int tmp;



signed main() {
	fastio;
	priority_queue<int, vector<int>, greater<int>> q;

	cin >> n;

	for (int i = 0; i < n * n; i++) {
		cin >> tmp;
		q.push(tmp);
		if (q.size() > n) q.pop();
	}
	
	cout << q.top();
	
}
