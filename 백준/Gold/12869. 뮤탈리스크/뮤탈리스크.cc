#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <tuple>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int n,m,sx,sy,ret,x,y;

int dp[64][64][64], a[3], visited[64][64][64];
int _a[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 9, 3},
	{1, 3, 9}
};


const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, -1, 0, 1 };
const int INF = 987654321;



struct A {
	int a, b, c;
};


void input();
void solve(int a, int b, int c);

int main() {
	fastio;
	input();
	solve(a[0], a[1], a[2]);
	return 0;
	
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
}

queue <A> q;
void solve(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a, b, c });
	while (q.size()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++) {
			int na = max(0, a - _a[i][0]);
			int nb = max(0, b - _a[i][1]);
			int nc = max(0, c - _a[i][2]);
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
	}
	cout << visited[0][0][0] - 1 << '\n';
	
}


