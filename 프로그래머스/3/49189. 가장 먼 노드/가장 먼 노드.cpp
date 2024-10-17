#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;






int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < edge.size(); i++)
    {
        int from = edge[i][0];
        int to = edge[i][1];
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    
    vector<int> dis(n + 1, -1);
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while(q.size())
    {
        int cur = q.front(); q.pop();
        for(int next : graph[cur])
        {
            if(dis[next] == -1)
            {
                dis[next] = dis[cur] + 1;
                q.push(next);
            }
        }
    }
    
    int mx = *max_element(dis.begin(), dis.end());
    
    for(int i = 0 ; i < dis.size(); i++)
    {
        if(mx == dis[i]) answer++;
    }
    
    return answer;
}

// 1. 인접 리스트로 그래프 형성
// 2. dfs 로 가장 먼 거리의 거리 구하고
// 3. 그 개수 새기