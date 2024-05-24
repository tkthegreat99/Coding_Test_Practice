#include<vector>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int visited[104][104];
int a[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int mn;
int x, y;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            a[i][j] = maps[i][j];
        }
    }
    fill(&visited[0][0] , &visited[0][0] + 104 * 104, -1);
  
    
    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0 ; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >=n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if(visited[ny][nx] > -1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    answer = visited[n-1][m-1];
    
    return answer;
}



