#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#include <math.h>
#include <deque>
#include <sstream>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define INF 987654321

using namespace std;

int n, m, x;
int mx = -1;

int dijtra(int start, int end, int n, vector<vector<pair<int, int>>> graph)
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (pq.size())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second; pq.pop();

        for (pair<int, int> k : graph[cur])
        {
            int nxt = k.second;
            int nxt_cost = cost + k.first;

            if (dist[nxt] > nxt_cost)
            {
                dist[nxt] = nxt_cost;
                pq.push({ -nxt_cost, nxt });
            }
        }
    }
    
    return dist[end];
}

signed main()
{
    fastio;

    cin >> n >> m >> x;
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>(0, { 0, 0 }));

    for (int i = 0; i < m; i++)
    {
        int from, to, len;
        cin >> from >> to >> len;
        graph[from].push_back({ len, to });
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp = dijtra(i, x, n, graph) + dijtra(x, i, n, graph);
        mx = max(mx, tmp);
    }
    cout << mx << '\n';

}



