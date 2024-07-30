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

int n;
int a[104][104];
int visited[104][104];
int cnt = 1;
int mn = 1e9;
map<int, pair<int, int>> mp;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = cnt;
	q.push({ y, x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 0 ) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = cnt;
			mp[cnt] = { ny, nx };
			q.push({ ny, nx });
		}
	}
}




static int distance(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void simulation(int y, int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] && (visited[i][j] != visited[y][x])) {
				mn = min(mn, distance({ i, j }, { y, x }));
			}
		}
	}
}

signed main() {
	fastio;


	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				simulation(i, j);
			}
		}
	}

	cout << mn - 1 << '\n';
	return 0;
}