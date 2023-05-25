#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <tuple>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n,m,h, mx, cnt;
int a[104][104][104];
int visited[104][104][104];
const int dy[] = { -1, 0, 1, 0 , 0, 0};
const int dx[] = { 0, -1, 0, 1 , 0, 0};
const int dz[] = { 0, 0, 0, 0, -1, 1 };
queue<tuple<int, int, int>> q;


void input();
void solve();
void bfs();

int main() {
	fastio;
	input();
	



	solve();
	return 0;
	
}

void input() {
	cin >> n >> m >> h;
	for (int i = 0; i < h; i++) {
		
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> a[i][j][k];
				if (a[i][j][k] == 1) {
					q.push({ i, j ,k });
					visited[i][j][k] = 1;
				}
				if (a[i][j][k] == -1) {
					visited[i][j][k] = -1;
				}
			}
		}

	}	

}

void solve() {


	bfs();
	int chk = 0;

	



	for (int k = 0; k < h; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

				if (a[k][i][j] == -1) {
					chk++;
					if (chk == (h * n * m)) {
						cout << -1 << '\n';
						return;
					}
				}

				if (visited[k][i][j] == 0) {
					cout << -1 << '\n';
					return;
				}
				mx = max(mx, visited[k][i][j]);
			}

		}
	}
	cout << mx - 1 << '\n';
	
}


void bfs() {

	
	
	
	while (q.size()) {
		tuple<int, int, int> t;

		t = q.front();
		int z = get<0>(t);
		
		int y = get<1>(t);
		int x = get<2>(t);

		
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= m || nx >= n) continue;
			if (visited[nz][ny][nx]) continue;
			if (a[nz][ny][nx] == -1) continue;
			if (a[nz][ny][nx] == 0) {
				visited[nz][ny][nx] = visited[z][y][x] + 1;
				q.push({ nz,ny, nx });
			}
		}
		
		
	}
}