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

int n, m;
int a[1000][1000];
int visited[2][1000][1000];
int cnt = 1;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
string str;

signed main() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, pair<int, int>>> q;
	visited[1][0][0] = 1;
	q.push({ 1, { 0, 0 } });
	while(q.size()) {
		int can = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		if (y == n - 1 && x == m - 1) {

			cout << visited[can][y][x];
			return 0;
		}


		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 1 && can == 1) {
				visited[0][ny][nx] = visited[1][y][x] + 1;
				q.push({ 0, { ny, nx } });
			}
			else if (a[ny][nx] == 0 && visited[can][ny][nx] == 0) {
				visited[can][ny][nx] = visited[can][y][x] + 1;
				q.push({ can, {ny, nx} });
			}
		}
		//cout << "hi" << '\n';
	}
	
	cout << -1 << '\n';


	return 0;
}

