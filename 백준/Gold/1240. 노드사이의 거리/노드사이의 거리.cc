#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;
const int INF = 987654321;
int n, m, w, n1, n2;
vector<pair<int, int>> adj[1004];
int visited[1004];
queue<int> q;
void input();
void solve(int start, int end);
int main() {
    fastio;
    input();
    return 0;
}
void input(){
    cin >> n >> m;
    for(int i = 0 ; i < n-1; i++) {
        cin >> n1 >> n2 >> w;
        adj[n1].push_back({n2, w});
        adj[n2].push_back({n1, w});

    }
    for(int i = 0 ; i < m; i++){
        cin >> n1 >> n2;
        solve(n1, n2);
    }
}

void solve(int start, int end){
    int sum = 0;
    fill(&visited[0], &visited[0] + 1004, -1);
    q.push(start);
    visited[start] = 0;
    while(q.size()){
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(visited[nxt.first] != -1) continue;
            visited[nxt.first] = visited[cur] + nxt.second;
            q.push(nxt.first);
        }
    }
    cout << visited[end] << '\n';
}


