#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;



int a[10][10];
int visited[1001];
vector<int> ve[1001];
int n, m, ret;


const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void DFS(int vertex) {
    visited[vertex] = 1;
    for (int i = 0; i < ve[vertex].size(); i++) {
        int idx = ve[vertex][i];
        if (!visited[idx]) DFS(idx);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int u, v;
    int cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);

    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << '\n';

    return 0;
}