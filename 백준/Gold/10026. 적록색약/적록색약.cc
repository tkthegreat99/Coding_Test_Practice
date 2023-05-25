#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>


#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n;
char a[104][104];
int visited[104][104];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };
int cnt_weak, cnt;
string tmp;

void input();
void solve();
void bfs_weak(int y, int x);
void bfs(int y, int x);

int main() {
	fastio;
	input();
	
	solve();
	return 0;
	
}

void input() {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			a[i][j] = tmp[j];
		}
	}

	
}

void solve() {

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	fill(&visited[0][0], &visited[0][0] + 104 * 104 , 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				cnt_weak++;
				bfs_weak(i, j);
			}
		}
	}

	
	cout << cnt << '\n' << cnt_weak << '\n';
}

void bfs_weak(int y, int x) {

	//처음 y, x가 빨강이나 초록일 경우 빨, 초를 둘다 감
	//파랑일 때는 안감(벽으로 취급)
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	if (a[y][x] == 'R' || a[y][x] == 'G') {
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (visited[ny][nx]) continue;
				if (a[ny][nx] == 'B') continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

		}
		return;
	}

	else {
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (visited[ny][nx]) continue;
				if (a[ny][nx] == 'R' || a[ny][nx] == 'G') continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

		}
		return;
	}

}

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	if (a[y][x] == 'R') {
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (visited[ny][nx]) continue;
				if (a[ny][nx] == 'B' || a[ny][nx] == 'G') continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

		}
		return;
	}
	else if (a[y][x] == 'G') {
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (visited[ny][nx]) continue;
				if (a[ny][nx] == 'B' || a[ny][nx] == 'R') continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

		}
		return;
	}
	else if (a[y][x] == 'B') {
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (visited[ny][nx]) continue;
				if (a[ny][nx] == 'R' || a[ny][nx] == 'G') continue;
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}

		}
		return;
	}
}

