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




int n, s;
int arr[21];
int visited[21];
int ret;

void go(int num, int tot) {

	if (num == n) {

		if (tot == s) {
			ret++;
		}
		return;
	}
	go(num + 1, tot);
	go(num + 1, tot + arr[num]);
}




signed main() {
	fastio;

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	go(0, 0);

	if (s == 0) ret--;

	cout << ret;

	return 0;
}