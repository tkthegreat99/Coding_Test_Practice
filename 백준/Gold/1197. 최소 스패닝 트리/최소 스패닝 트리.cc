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

int check[10001];
int v, e;
int from, to, weight;

signed main()
{
    fastio;
    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>(0, {0, 0}));

    for (int i = 0; i < e; i++)
    {
        cin >> from >> to >> weight;
        graph[from].push_back({ weight, to });
        graph[to].push_back({ weight, from });
    }

    int cnt = 0;
    int tot = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    check[1] = 1;

    for (pair<int, int> k : graph[1])
    {
        pq.push(k);
    }

    

    while (cnt < v - 1)
    {
        int next = pq.top().second;
        int curWeight = pq.top().first; pq.pop();

        //cout << next << " " << curWeight << '\n';

        if (!check[next])
        {
            tot += curWeight;
            cnt++;
            check[next] = 1;
          //  cout << "cnt :  " << cnt << '\n';
        }
        else continue;
        for (pair<int, int> k : graph[next])
        {
            if(!check[k.second]) pq.push(k);
        }
    }
    
    cout << tot << '\n';
    
    
}


/*
프림 알고리즘

첫 번째 노드를 아무거나 고르고, 해당 노드에 연결된 것들을 최소 힙에 넣어놓고 중 최소 인것을 선택한다.



*/