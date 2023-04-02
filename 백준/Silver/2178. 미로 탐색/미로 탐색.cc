#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#pragma warning(disable: 4996)

using namespace std;

int a[104][104];
int visited[104][104];



const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };


int n, m;
int y, x;


int main() {

	

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;    // 이미 방문했다면
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	printf("%d", visited[n - 1][m - 1]);

	return 0;
}