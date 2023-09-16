#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;

/* Method Initialization */
void input();
void solve();
void dfs(int y, int x, int dep, int sum);
int mPm(int i, int j);
/* Variable Initialization */
int n, m, mx = -1e9;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int a[504][504];
int visited[504][504];

int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input(){
    cin >> n >> m;
    for(int i =0 ;i < n; i++)
        for(int j= 0 ; j < m; j++)
            cin >> a[i][j];
}

void solve() {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            dfs(i, j, 0, a[i][j]);
            mx = max(mPm(i, j), mx);
        }
    }
    cout << mx << '\n';
}

void dfs(int y, int x, int dep, int sum)
{
    if(dep == 3){
        mx = max(mx, sum);
        return;
    }

    visited[y][x] = 1;
    for(int i = 0 ; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || nx >= m || ny >= n) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, dep + 1, sum + a[ny][nx]);
        visited[ny][nx] = 0;
    }
    visited[y][x] =  0;
}

int mPm(int i, int j){
    int tmpmx = -1;
    int tmp = 0;

    if( j - 1 >=0 && j + 1 < m && i - 1 >=0){
        tmp = a[i][j-1] + a[i][j] + a[i][j + 1] + a[i - 1][j];
        tmpmx = max(tmpmx, tmp);
    }
    if( i - 1 >=0 && j + 1 < m && i + 1 < n){
        tmp = a[i-1][j] + a[i][j] + a[i][j + 1] + a[i + 1][j];
        tmpmx = max(tmpmx, tmp);
    }
    if( j - 1 >=0 && j + 1 < m && i + 1 < n){
        tmp = a[i][j-1] + a[i][j] + a[i][j + 1] + a[i + 1][j];
        tmpmx = max(tmpmx, tmp);
    }
    if( j - 1 >=0 && i + 1 < n && i - 1 >=0){
        tmp = a[i][j-1] + a[i][j] + a[i + 1][j] + a[i - 1][j];
        tmpmx = max(tmpmx, tmp);
    }
    return tmpmx;
}

