#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n, m, mx = -987654321, cnt; 
int a[504][504];
int visited[504][504];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };



void input();
void solve();
void bfs(int y, int x);


int main() {
	fastio;
	input();
	solve();
	return 0;
}


void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}

void solve() {
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && a[i][j] == 1) {
				
				bfs(i, j);
				cnt++;
				flag = true;
			}
		}
	}
	if (!flag) mx = 0;
	cout << cnt << '\n' << mx << '\n';

}

void bfs(int y, int x) {
	
	queue<pair<int, int>> q;
	int ret = 0;
	visited[y][x] = 1;
	q.push({ y, x });
	++ret;
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 0) continue;
			visited[ny][nx] = 1;
			++ret;
			q.push({ ny, nx });
			
		}
		mx = max(ret, mx);
	}
}