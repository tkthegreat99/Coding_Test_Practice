#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, tmp1, tmp2, cnt;
vector<int> adj[100];
int visited[100];
vector<pair<int, int>> ret;


void input();
void solve();
int main() {
    fastio;
    input();
    solve();
    return 0;
}
void input(){
    cin >> n >> m;
    while(m--) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
//    cout << "input finish" << '\n';
}

void solve(){

    for(int i = 1 ; i <= n; i++) {
        queue<int> q;
        fill(&visited[0], &visited[0] + 100, 0);
        q.push(i);
        while(q.size()){
            int here = q.front(); q.pop();
            for(int there : adj[here]){
                if(visited[there]) continue;
                visited[there] = visited[here] + 1;
                q.push(there);
            }
        }
        visited[i] = 0;
        for(int i = 1 ; i <=n; i++) {
            cnt += visited[i];
        }
        ret.push_back({i, cnt});
        cnt = 0;
    }
    /*
    cout << "**ret queue test**"<< '\n';
    for(pair<int, int> q : ret) cout << q.first << " " << q.second << '\n';
    */
    int mn = 1e9;
    int idx;
    for(pair<int, int> se : ret){
        if(se.second < mn){ mn = se.second; idx = se.first;}
    }
    cout << idx << '\n';

}
