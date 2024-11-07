#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

int d[51];
int visited[51];


void djstra(int start, vector<vector<pair<int, int>>>& graph)
{
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while(pq.size())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(d[now] < dist) continue;
        for(int i =0 ; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].first;
            if(cost < d[graph[now][i].second])
            {
                d[graph[now][i].second] = cost;
                pq.push(make_pair(-cost,graph[now][i].second));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>(0, {0, 0}));
    fill(d, d + 51, INF);
    
    int n = road.size();
    for(int i = 0 ; i < n; i++)
    {
        int from = road[i][0];
        int to = road[i][1];
        int weight = road[i][2];
        graph[from].push_back({weight, to});
        graph[to].push_back({weight, from});
    }
    
    djstra(1, graph);
    
    for(int i =1  ; i <= N; i++)
    {
        if(d[i] <= K) answer++;
    }
    
    
    
    

    return answer;
}

/*
1q번 마을에서 각 마을로 음식 배달
n개의 마을 중에서 k 시간 이하로 갈 수 있는 데만 감


*/