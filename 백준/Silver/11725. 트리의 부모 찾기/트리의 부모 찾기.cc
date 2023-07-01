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
int n, m1, m2;
vector<int> adj[100004];
int visited[1000004];
vector<pair<int, int>> p;
bool cmp(pair<int, int> p, pair<int, int> q);
void input();
void solve();
int main() {
    fastio;
    input();
    solve();
    return 0;
}
void input(){
    cin >> n;
    for(int i = 0 ; i < n-1; i++){
        cin >> m1 >> m2;
        adj[m1].push_back(m2);
        adj[m2].push_back(m1);
    }
}

void solve(){
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(q.size()){
        int here = q.front(); q.pop();
        for(int there : adj[here]){
            if(visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
            p.push_back({here, there});
        }
    }

//    for(int i = 1 ; i <= n; i++) cout << visited[i] - 1 << '\n';

    sort(p.begin(), p.end(), cmp);

//    for(pair<int, int> t : p){
//        cout << t.first << ":" << t.second << '\n';
//    }

    for(pair<int, int> t : p){
        cout << t.first << '\n';
    }
}

bool cmp(pair<int, int> p, pair<int, int> q){
    if(p.second < q.second) return true;
    else return false;
}

