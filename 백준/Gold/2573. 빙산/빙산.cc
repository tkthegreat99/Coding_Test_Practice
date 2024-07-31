#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <limits.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, m;
int a[301][301];
int visited[301][301];
int minu[301][301];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int t;
int num;


int count(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx]) continue;
		cnt++;
	}
	return cnt;
}



void melting() {

	fill(&minu[0][0], &minu[0][0] + 301 * 301, 0);
	t++;
	
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}

	cout << "*****************" << '\n';
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				minu[i][j] += count(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				a[i][j] -= minu[i][j];
				if (a[i][j] < 0) a[i][j] = 0;
			}
		}
	}


	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	*/
}

void bfs(int y, int x) {

	

	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (!a[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	*/
}



signed main() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int chk = 0;
	while (1) {
		num = 0;
		chk = 0;
		fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] && !visited[i][j]) {
					chk = 1;
					bfs(i, j);
					num++;
				}
			}
		}
		if (num >= 2) break;
		else if (chk == 0 && num <= 0) {
			cout << 0;
			return 0;
		}

		melting();

	}

	cout << t;
	
	return 0;
}