#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#include <math.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int w, h, t;
char a[1001][1001];
vector<pair<int, int>> fire;
pair<int, int> start;
int visited_fire[1001][1001];
int visited_sang[1001][1001];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

signed main() {
	fastio;

	cin >> t;
	while (t--) {
		int chk = 0;
		fire.clear();

		fill(&visited_fire[0][0], &visited_fire[0][0] + 1001 * 1001, 1e10);
		fill(&visited_sang[0][0], &visited_sang[0][0] + 1001 * 1001, 0);
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
				if (a[i][j] == '*') fire.push_back({ i, j });
				if (a[i][j] == '@') start = { i, j };
			}
		}

		if (start.first == 0 || start.second == 0 || start.first == h - 1 || start.second == w - 1) {
			cout << 1 << '\n';
			continue;
		}

		queue<pair<int, int>> qt;
		for (pair<int, int> v : fire) {
			visited_fire[v.first][v.second] = 1;
			qt.push({ v.first, v.second });
		}
		int y, x;
		while (qt.size()) {
			tie(y, x) = qt.front(); qt.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (visited_fire[ny][nx] != 1e10) continue;
				if (a[ny][nx] == '#') continue;
				visited_fire[ny][nx] = visited_fire[y][x] + 1;
				qt.push({ ny, nx });
			}
		}
		queue<pair<int, int>> q;
		visited_sang[start.first][start.second] = 1;
		q.push({ start.first, start.second });
		while (q.size()) {
			tie(y, x) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (visited_sang[ny][nx]) continue;
				if (a[ny][nx] == '#') continue;
				visited_sang[ny][nx] = visited_sang[y][x] + 1;
				if (ny == 0 || nx == 0 || ny == h-1 || nx == w-1) {
					if (visited_sang[ny][nx] < visited_fire[ny][nx]) {
						chk = 1;
						cout << visited_sang[ny][nx] << '\n';
						break;
					}
				}
				q.push({ ny, nx });
			}
			if (chk == 1) break;
		}
		if (chk == 0) cout << "IMPOSSIBLE\n";
		/*
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << visited_fire[i][j] << " ";
			}
			cout << '\n';
		}
		cout << "sang\n";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << visited_sang[i][j] << " ";
			}
			cout << '\n';
		}
		*/
		
	}
	

	
}
