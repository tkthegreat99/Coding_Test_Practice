#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int solution(vector<string> board)
{
    int n = board.size(), m = board[0].size();
    int vis[100][100]; memset(vis,-1,sizeof(vis));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(board[i][j] == 'R') q.push({i,j});
    vis[q.front().first][q.front().second] = 0;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int dir=0;dir<4;dir++)
        {
            int nx = cur.first, ny = cur.second;
            while (1)
            {
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                if (board[nx][ny] == 'D') break;
                nx += dx[dir];
                ny += dy[dir];
            }
            nx -= dx[dir];
            ny -= dy[dir];
            if (board[nx][ny] == 'G') return (vis[cur.first][cur.second] + 1);
            if (vis[nx][ny]>=0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    return (-1);
}