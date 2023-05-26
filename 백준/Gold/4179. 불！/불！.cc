#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <tuple>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n,m,sx,sy,ret,x,y;

char a[1004][1004];
int visited_fire[1004][1004];
int visited_man[1004][1004];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };
const int INF = 987654321;

queue < pair<int, int>> q;


void input();
int solve();

int main() {
	fastio;
	input();
	solve();
	return 0;
	
}

void input() {
	cin >> n >> m;
	fill(&visited_fire[0][0], &visited_fire[0][0] + 1004 * 1004, INF);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'F') {
				visited_fire[i][j] = 1; q.push({ i, j });
			}
			else if (a[i][j] == 'J') {
				sy = i; sx = j;
			}
		}
	}
}

int solve() {
	
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited_fire[ny][nx] != INF || a[ny][nx] == '#') continue;
			visited_fire[ny][nx] = visited_fire[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	visited_man[sy][sx] = 1;
	q.push({ sy, sx });
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x == m - 1 || y == n - 1 || x == 0 || y == 0) {
			ret = visited_man[y][x];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited_man[ny][nx] || a[ny][nx] == '#') continue;
			if (visited_fire[ny][nx] <= visited_man[y][x] + 1) continue;
			visited_man[ny][nx] = visited_man[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (ret != 0) cout << ret << '\n';
	else cout << "IMPOSSIBLE" << '\n';
	return 0;
	
}


