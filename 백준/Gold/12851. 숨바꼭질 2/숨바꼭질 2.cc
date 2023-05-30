#include<iostream>
#include<queue>
#include<algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

const int MAX = 100000;
int visited[MAX + 4];
long long cnt[MAX + 4];





int n, m;
void input();
void solve();
void bfs();

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
		puts("0");
        puts("1");
        return;
	}
	bfs();
}

void bfs() {
	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : {now - 1, now + 1, now * 2}) {
			if (0 <= next && next <= MAX) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
				}
				else if (visited[next] == visited[now] + 1) {
					cnt[next] += cnt[now];
				}
			}
		}
	}
	cout << visited[m] - 1 << '\n';
	cout << cnt[m] << '\n';
    return;
}