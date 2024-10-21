#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int visited[101];
int cnt;
int mn = 999999999;
vector<vector<int>> graph2;

void dfs(int cur, pair<int, int> Not, pair<int, int> Not2)
{
    cnt++;
    visited[cur] = 1;
    for(int next : graph2[cur])
    {
        if(make_pair(cur, next) == Not || make_pair(cur, next) == Not2) continue;
        if(!visited[next])
        {
            dfs(next, Not, Not2);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<vector<int>> graph(n + 1);
    
    for(int i = 0; i < wires.size(); i++)
    {
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    // 그래프 완셩
    
    graph2 = graph;
    
    for(int i = 0 ; i < wires.size(); i++)
    {
        fill(visited, visited + 101, 0);
        cnt = 0;
        pair<int, int> DeletedEdge1;
        pair<int, int> DeletedEdge2;
        DeletedEdge1 = {wires[i][0], wires[i][1]};
        DeletedEdge2 = {wires[i][1], wires[i][0]};
        
        dfs(1, DeletedEdge1, DeletedEdge2);
        
        int bigger = n - cnt > cnt ? n - cnt : cnt;
        int smaller = n - cnt < cnt ? n - cnt : cnt;
        mn = min(mn, bigger - smaller);
        //cout << bigger << " " << smaller << '\n';
    }
        
    answer = mn;
        
    
    return answer;
}
//먼저 인접그래프로 트리를 형성
// 하나씩 끊어보면서 bfs 로 노드 수를 셈.
// 차이를 계산해서 최소값을 찾는다.

// 만들어야할 함수 : 