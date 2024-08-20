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


int l, r, c;
char building[30][30][30];
int visited[30][30][30];
const int dz[6] = { 1, -1, 0, 0, 0, 0};
const int dy[6] = { 0, 0, -1, 0, 1, 0 };
const int dx[6] = { 0, 0, 0, 1, 0, -1 };
int chk;

signed main() {
	fastio;

	while (1) {

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					visited[i][j][k] = 0;
				}
			}
		}

		
		
		chk = 0;
		cin >> l >> r >> c;
		if (!(l | r | c)) return 0;
		pair<int, pair<int, int>> start;
		pair<int, pair<int, int>> dest;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') start = { i, { j, k } };
					else if (building[i][j][k] == 'E') dest = { i, {j, k} };
				}
			}
		}

		queue<pair<int, pair<int, int>>> q;
		visited[start.first][start.second.first][start.second.second] = 1;
		q.push(start);
		while (q.size()) {
			int z = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c) continue;
				if (visited[nz][ny][nx]) continue;
				if (building[nz][ny][nx] == '#') continue;
				visited[nz][ny][nx] = visited[z][y][x] + 1;
				if (building[nz][ny][nx] == 'E') {
					chk = 1;
					break;
				}
				q.push({ nz, { ny, nx } });
			}
		}

		if (!chk) cout << "Trapped!" << '\n';
		else cout << "Escaped in " << visited[dest.first][dest.second.first][dest.second.second] - 1 << " minute(s).\n";
	}



	return 0;
}

