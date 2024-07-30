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

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int cleaned[51][51];
int a[51][51];
int n, m;
int d;
int cnt;
int px, py;
vector<pair<int, int>> v = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//0 북쪽 1 동쪽 2 남쪽 3 서쪽

int IsTherePlace(int y, int x) {
	int chk = 0;

	for(int i = 0 ; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (a[ny][nx] == 1) continue;
		if (cleaned[ny][nx]) continue;
		chk = 1;
	}
	return chk;
}

void function1(int y, int x) {
	cleaned[y][x] = 1;
	cnt++;
}

pair<int, int> function2(int y, int x) {

	int di = (d + 2) % 4;
	if (a[y + v[di].first][x + v[di].second] == 0) return { y + v[di].first, x + v[di].second };
	else return { -1, -1 };
}

pair<int, int> function3(int y, int x) {
	d = d - 1;
	if (d == -1) d = 3;
	if (a[y + v[d].first][x + v[d].second] == 0 && cleaned[y + v[d].first][x + v[d].second] == 0) {
		return { y + v[d].first, x + v[d].second };
	}
	else return { y, x };
}


signed main() {
	fastio;
	
	cin >> n >> m;
	cin >> py >> px >> d;
	int flag = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int k = 0;

	while (1) {

	

		if (!cleaned[py][px]) function1(py, px);
		
		flag = IsTherePlace(py, px);
		//cout << flag << " " << cnt << '\n';
		if (!flag) {
			tie(py, px) = function2(py, px);
			if (py == -1 && px == -1) break;
		}
		else {
			tie(py, px) = function3(py, px);
		}
		

	}

	cout << cnt;

	
	return 0;
}