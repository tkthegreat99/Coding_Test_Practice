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
#include <deque>
#include <sstream>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

char a[51][51];
int visited[51][51];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
int mx = -1;

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	while (q.size())
	{
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (a[ny][nx] == 'W') continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			mx = max(mx, visited[ny][nx]);
			q.push({ ny, nx });
		}
	}
}



signed main()
{
	fastio;

	
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
			if (a[i][j] == 'L') bfs(i, j);

		}
	}

	cout << mx - 1<< '\n';
}

/*
1. 맵을 그리고
2. W는 못감, L만 갈수 있음.
3. 모든 L에서 visited 배열을 만들어내고 mx 값을 얻어냄.

*/