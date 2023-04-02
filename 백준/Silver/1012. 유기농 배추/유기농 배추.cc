#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#pragma warning(disable: 4996)

using namespace std;

int a[51][51];
bool visited[51][51];



const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };


int n, m, T;
int y, x, k;
int ret;


void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
		if (a[ny][nx] == 1&& !visited[ny][nx]) dfs(ny, nx);
	}
	return;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> T;
	while (T--) {
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

		ret = 0;
		cin >> m >> n >> k;
		
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			a[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					ret++;
				}
			}
		}
		cout << ret << '\n';
	}
	return 0;
}