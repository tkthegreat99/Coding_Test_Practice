#include<vector>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int visited[101][101];

int y, x;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while(q.size())
    {
        tie(y, x) = q.front(); q.pop();
        for(int i = 0 ; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || nx >= m || ny >= n) continue;
            if(visited[ny][nx] || !maps[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    if(visited[n-1][m-1] == 0) return -1;
    
    
    answer = visited[n - 1][m - 1];
    
    return answer;
}



