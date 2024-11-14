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

int n, m;
int from, to, len;

signed main()
{
    fastio;

    cin >> n;
    cin >> m;
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>(0, { 0, 0 }));
    for (int i = 0; i < m; i++)
    {
        
        cin >> from >> to >> len;
        graph[from].push_back({ len, to });
        graph[to].push_back({ len, from });
    }

    vector<int> check(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int tot = 0;
    int cnt = 0;

    check[from] = 1;
    for (pair<int, int> k : graph[from])
    {
        pq.push({ k.first, k.second });
    }

    while (cnt < n - 1)
    {
        int cur = pq.top().second;
        int weight = pq.top().first; pq.pop();

        if (check[cur]) continue;
        check[cur] = 1;
        tot += weight;
        cnt++;

        for (pair<int, int> k : graph[cur])
        {
            if (!check[k.second]) pq.push({ k.first, k.second });
        }
    }
    
    cout << tot;



}



