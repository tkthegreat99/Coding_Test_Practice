#include <iostream>
#include <algorithm>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };


int a[100][100];
int visited[100][100];

int n;
int ret;

void dfs(int y, int x, int d) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (a[ny][nx] > d && !visited[ny][nx]) dfs(ny, nx, d);
	}
}


int main() {
	
	int ans = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int d = 0; d <= 100; d++) {
		ret = 0;

		fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > d && !visited[i][j]) {
					dfs(i, j, d);
					ret++;
				}
			}
		}
		ans = max(ret, ans);
	}


	cout << ans << '\n';
}