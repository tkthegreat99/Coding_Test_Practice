#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;



const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0,-1, 0, 1 };
int a[104][104];
int visited[104][104];
int visited_for_chk[104][104];
int n, m, cnt;
vector<pair<int, int>> v;
vector<pair<int, int>> v2;

void input();
void solve();
int cheese();
void bfs(int y, int x);
int cnt_zero(int y, int x);
void bfs_for_chk(int y, int x);


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


void bfs(int y, int x) {
	v.clear();
	fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 1) {
				v.push_back({ ny, nx });
				continue;
			}
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	cnt++;
	for (pair<int, int> k : v) {
		if (cnt_zero(k.first, k.second)) v2.push_back({ k.first, k.second });
	}

	for (pair<int, int> t : v2) {
		a[t.first][t.second] = 0;
	}

	
}

int cheese() {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				flag = 1;
			}
		}
	}
	if (flag) {
		return 1;
	}
	else return 0;
}



void bfs_for_chk(int y, int x) {
	queue<pair<int, int>> q2;
	fill(&visited_for_chk[0][0], &visited_for_chk[0][0] + 104 * 104, 0);
	visited_for_chk[y][x] = 1;

	q2.push({ y, x });
	while (q2.size()) {
		tie(y, x) = q2.front(); q2.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited_for_chk[ny][nx]) continue;
			if (a[ny][nx] == 1) {
				continue;
			}
			visited_for_chk[ny][nx] = visited_for_chk[y][x] + 1;
			q2.push({ ny, nx });
		}
	}



}


int cnt_zero(int y, int x) {

	
	int chk = 0;
	if (visited[y+1][x] != 0&& a[y+1][x] == 0) chk++;
	if (visited[y - 1][x] != 0&& a[y - 1][x] == 0) chk++;
	if (visited[y ][x+ 1] != 0 && a[y][x + 1] == 0) chk++;
	if (visited[y ][x-1] != 0 && a[y][x- 1] == 0) chk++;
	
	if (chk >= 2) return 1;
	else return 0;
}

void solve() {
	while (cheese()) {
		bfs(0, 0);
	}
	cout << cnt << '\n';
}
