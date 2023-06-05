#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define prev aaa
using namespace std;


int n, k;
void input();
void solve();
void bfs(int here);

const int MAX = 200004;
int visited[MAX];
vector<int> v;
int prev[MAX];
int next;

queue<int > q;

int main() {
	fastio;
	input();
	solve();
	return 0;
}

void input() {
	cin >> n >> k;
}

void solve() {
	if (n == k) {
		cout << 0 << '\n';
		cout << n << '\n';
		return;
	}

	bfs(n);
	return;

}

void bfs(int here) {
	
	q.push(here);
	visited[here] = 1;
	while (q.size()) {
		int here = q.front(); q.pop();
		if (here == k) {
			break;
		}
		for (int there : {here - 1, here + 1, here * 2 }) {
			if (there < 0 || there >= MAX || visited[there]) continue;
			if (!visited[there]) {
				visited[there] = visited[here] + 1;
				prev[there] = here;
				q.push(there);
			}


		}
	}
	for (int i = k; i != here; i = prev[i]) {
		v.push_back(i);
	}
	v.push_back(here);
	cout << visited[k] - 1 << '\n';
	reverse(v.begin(), v.end());
	for (int i : v) cout << i << ' ';
	return;
}