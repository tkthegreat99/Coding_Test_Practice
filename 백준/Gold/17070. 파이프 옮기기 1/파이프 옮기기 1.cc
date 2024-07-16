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
//#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, r, c;
int a[17][17];
int dp[17][17][3];

const int dy[] = { 1, 1, 0 };
const int dx[] = { 0, 1, 1 };
int visited[17][17];


/*
void dfs(int y, int x) {
	queue < pair<int, int>> q;
	visited[y][x] = 1;
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 3; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
		}
	}
}

*/


/*

(n, n) 으로 갈 수 있는 방법

(n-1, n-1) 에서 대각선으로 오기
-> 

(n-1, n)에서 세로로 오기
->

(n, n-1)에서 가로로 오기
->


*/


bool check(int y, int x, int d) {
	if (d == 0 || d == 2) {
		if (!a[y][x]) return true;
	}
	else if (d == 1) {
		if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true;
	}
	return false;
}




//0 가로 1 대각선 2 세로
int main() {

	fastio;


	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

			if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
			if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
			if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	int ret = 0;
	ret += dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	cout << ret << '\n';
	return 0;




}