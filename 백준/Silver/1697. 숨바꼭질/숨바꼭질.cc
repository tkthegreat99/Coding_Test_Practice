#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
void input();
void solve();
void bfs();
const int MAX = 100000;
int visited[MAX + 4];



int main() {
	fastio;
	input();
	solve();
}

void input() {
	cin >> n >> m;
}


void solve() {
	if (n == m) {
		cout << 0 << '\n';
		return;
	}
	bfs();
}



void bfs() {
	queue<int> q;
	visited[n] = 1;
	q.push(n);
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : {now - 1, now + 1, 2 * now}) {
			if (next >= 0 && next <= MAX) {
				if (!visited[next]) {
					visited[next] = visited[now] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << visited[m] - 1 << '\n';
}