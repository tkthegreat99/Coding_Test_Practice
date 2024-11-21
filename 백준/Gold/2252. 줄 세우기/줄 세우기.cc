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


signed main()
{
    fastio;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        indegree[to]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0) q.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (q.empty()) return 0;

        int _from = q.front();
        cout << _from << " ";
        q.pop();
        for (int next : graph[_from])
        {
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }

    return 0;
}



