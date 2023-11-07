#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

/* Method Initialization */
void input();
void solve();
void dfs(int y, int x, int dir);

/* Variable Initialization */
int n;
int dy[3] = {0, 1, 1};
int dx[3] = {1, 0, 1};
int a[17][17];
int ret;

int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void solve()
{
    dfs(1, 2, 0);
    cout << ret << '\n';
}

void dfs(int y, int x, int dir){
    if(y == n && x == n){
        ret++;
        return;
    }
    for(int i = 0; i < 3; i++){

        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny > n || nx > n) continue;
        if(a[ny][nx] == 1) continue;
        if(i == 2 && (a[y + 1][x] == 1 || a[y][x+1] == 1)) continue;
        if(dir == 0 && i == 1) continue;
        if(dir == 1 && i == 0) continue;
        dfs(ny, nx, i);
    }
}




