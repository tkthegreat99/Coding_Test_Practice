
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[1004];
int visited[1004];


int n, m, k, tmp, tmp2;

void dfs(int here) {
    cout << here << ' ';
    visited[here] = 1;
    
    for (int there : adj[here]) {
        if (visited[there]) continue;
        dfs(there);
    }
}

void bfs(int here) {
    queue<int> q;
    q.push(here);
    visited[here] = 1;
    cout << here << ' ';
    
    while (q.size()) {
        int here = q.front(); q.pop();
        for (int there : adj[here]) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
            cout << there << ' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);



    cin >> n >> m >> k;
    while (m--) {
        cin >> tmp >> tmp2;
        adj[tmp].push_back(tmp2);
        adj[tmp2].push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(k);
    cout << '\n';
    memset(visited, 0, sizeof(visited));
    bfs(k);
}
