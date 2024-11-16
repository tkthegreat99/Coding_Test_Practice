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

int v, e;
int check[10001];



signed main()
{
    fastio;
    
    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>(0, { 0, 0 }));

    for (int i = 0; i < e; i++)
    {
        int from, to, len;
        cin >> from >> to >> len;
        graph[from].push_back({ len, to });
        graph[to].push_back({ len, from });
    }


    int cnt = 0;
    int tot = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    check[1] = 1;

    for (pair<int, int> k : graph[1])
    {
        pq.push({ k.first, k.second });
    }

    while (cnt < v - 1)
    {
        int cur = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        
        if (check[cur]) continue;
        check[cur] = 1;
        tot += weight;
        cnt++;

        for (pair<int, int> k : graph[cur])
        {
            if (!check[k.second]) pq.push({ k.first, k.second });
        }

    }

    cout << tot << '\n';
    

}



