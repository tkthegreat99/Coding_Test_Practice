#include <string>
#include <vector>

using namespace std;
int visited[201];

void dfs(int cur, int n, vector<vector<int>> computers)
{
    visited[cur] = 1;
    
    for(int i = 0; i <n; i++)
    {
        if(!visited[i] && computers[cur][i])
        {
            dfs(i, n, computers);    
        }
    }
    
}



int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, n, computers);
            answer++;
        }
    }
    
    
    return answer;
}