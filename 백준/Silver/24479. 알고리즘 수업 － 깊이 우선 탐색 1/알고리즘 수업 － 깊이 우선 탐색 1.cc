
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> adj[100004];
int visited[100004];
int result[100004];
int n, m, k;
int tmp, tmp2;
int cnt;


void dfs(int here) {
    visited[here] = 1;
    cnt++;
    result[here] = cnt;
    for (int there : adj[here]) {
        if (visited[there]) continue;
        dfs(there);
    }
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> tmp >> tmp2;
        adj[tmp].push_back(tmp2);
        adj[tmp2].push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(k);
    for (int i = 1; i <= n; i++) {
        cout << result[i] << '\n';
    }

}
