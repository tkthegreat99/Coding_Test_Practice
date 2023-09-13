#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;

/* Method Initialization */
void input();
void solve();
void bfs(int y);

/* Variable Initialization */
int n, m, mn = 1e9;
map<int, int> mp;
int u, v;
int visited[104];
int a[104];


int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input()
{
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> u >> v;
        mp[u] = v;
    }
    for (int i = 0 ; i < m; i++){
        cin >> u >> v;
        mp[u] = v;
    }
}

void solve()
{
    fill(&visited[0], &visited[0] + 104, 999999);
    bfs(1);
    cout << visited[100] - 1 << '\n';
}

void bfs(int y)
{
    queue<int> q;
    visited[y] = 1;
    q.push(y);
    while(q.size()){
        int here = q.front(); q.pop();
        for(int i = 1; i <= 6; i++){
            int there = here + i;
            if(there > 100) continue;
            if(mp[there] != 0) there = mp[there];
            if(visited[there] > visited[here]){
                visited[there] = visited[here] + 1;
                q.push(there);
            }
        }
    }
}


