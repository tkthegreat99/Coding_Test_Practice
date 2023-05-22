
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int n, m, mx, visited[100004];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
char a[54][54];
vector<int> adj[100004];
int u, v;
//bfs 식
int r;
int seq;

void input();
void bfs(int here);
void sol();

int ret[100004];

int main() {

    fastio;
    input();
    sol();
    return 0;
}


void input() {
    cin >> n >> m >> r;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
}

void bfs(int here) {
    queue<int> q; // 큐 생성
    q.push(here); // 큐에 지금 위치 넣rh
    visited[here] = ++seq;

    while (q.size()) {
        int tmp = q.front(); q.pop();
        for (int there : adj[tmp]) { // 해당 위치랑 연결된 애들 탐색하
            if (visited[there]) continue;
            visited[there] = ++seq;
            q.push(there);
        }
    }
}

void sol() {
    bfs(r);
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}
