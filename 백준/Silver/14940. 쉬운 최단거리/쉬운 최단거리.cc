#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n, m;
void input();
void solve(int y, int x);
int target_y, target_x;


const int MAX = 1000;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int visited[MAX + 4][MAX + 4];
int a[MAX + 4][MAX + 4];



int main() {
	fastio;
	input();
	solve(target_y, target_x);
	return 0;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				target_y = i;
				target_x = j;
			}
		}
	}
}

void solve(int y, int x) {
	fill(&visited[0][0], &visited[0][0] + 1004 * 1004, 0);
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || a[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) visited[i][j] = 1;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] - 1 << ' ';
		}
		cout << '\n';
	}

}