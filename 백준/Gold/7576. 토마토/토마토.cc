#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n, m, mx = -987654321, cnt; 
int a[1004][1004];
int visited[1004][1004];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

vector <pair<int, int>> v;


void input();
int solve();
void bfs();


int main() {
	fastio;
	input();
	solve();
	return 0;
}


void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i, j });
				visited[i][j] = 1;
			}
			if (a[i][j] == -1) {
				visited[i][j] = -1;
			}
		}
	}
}

int solve() {

	

	bfs();
	/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	*/
	

	int chk = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			if (a[i][j] == -1) {
				chk++;
				if (chk == (n * m)) {
					cout << -1 << '\n';
					return 0;
				}
			}
			
			if (visited[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			mx = max(mx, visited[i][j]);
		}
		
	}
	cout << mx - 1 << '\n';
	return 0;
}

void bfs() {
	
	
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= m || nx < 0 || nx >=n) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == -1) continue;
			if (a[ny][nx] == 0) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
		
	}
	
}