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



int k, s;
int arr[13];
vector<int> v;

void go(int idx, int size) {

	if (v.size() == 6) {
		for (int i = 0; i < 6; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < k; i++) {
		v.push_back(arr[i]);
		go(i + 1, size + 1);
		v.pop_back();
	}
}


signed main() {
	fastio;

	while (1) {


		cin >> k;

		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		go(0, 0);
		cout << '\n';

	}


	return 0;
}