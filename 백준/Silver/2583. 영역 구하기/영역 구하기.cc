#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };


int a[101][101];
int visited[101][101];

int m,n,k;

int x_1, x_2, y_1, y_2;

int dfs(int y, int x) {
	int ret = 1;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1) continue;
		if (a[ny][nx] == 1) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}


int main() {
	vector<int> ans;
	

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int t = x_1; t < x_2; t++) {
			for (int f = y_1; f < y_2; f++) {
				a[f][t] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 1 && visited[i][j] == 0) {
				ans.push_back(dfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << " ";


}