#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


//bfs를 하는데, bfs에서 확인을 해야한다. L, R에 대해. 
//그리고 갈 수 있는 곳들의 합과, 좌표들을 모두 저장해놔야 한다. 



int n, m, visited[54][54], mx;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int a[54][54];
int sum, cnt;
int L, R;
vector<pair<int, int>> v;



void dfs(int y, int x, vector<pair<int, int>>& v) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (abs(a[ny][nx] - a[y][x]) >= L && abs(a[ny][nx] - a[y][x]) <= R) {
			visited[ny][nx] = 1;
			v.push_back({ ny, nx }); // 좌표 저장해주고
			sum += a[ny][nx];
			dfs(ny, nx, v);
		}
	}
}



int main() {
	fastio;
	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		bool flag = 0;
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i, j });
					sum = a[i][j];
					dfs(i, j, v);
					if (v.size() == 1) continue;
					for (pair<int, int> b : v) {
						a[b.first][b.second] = sum / v.size();
						flag = 1;
					}
				}

			}
		}
		if (!flag) break;
		cnt++;
	}

	cout << cnt << '\n';
	return 0;
}