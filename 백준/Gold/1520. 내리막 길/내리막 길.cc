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
void dfs(int y, int x);

/* Variable Initialization */
int n, m;
int a[504][504];
int visited[504][504];
const int dy[] = {-1 ,0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int ret;

int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input(){
    cin >> m >> n;
    for(int i = 0 ; i < m; i++){
        for(int j = 0 ; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void solve() {
    if(m == 1 || n == 1) {
        cout << 1 << '\n';
        return;
    }
    fill(&visited[0][0], &visited[0][0] + 504 * 504, -1);
    dfs(0, 0);
    cout << visited[0][0] << '\n';
}

void dfs(int y, int x){
     visited[y][x] = 0;
    if(y == m - 1 && x == n - 1){
        visited[y][x]++;
        return;
    }
     for(int i = 0 ; i < 4; i++){
         int ny = y + dy[i];
         int nx = x + dx[i];
         if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
         if(a[ny][nx] >= a[y][x]) continue;
         if(visited[ny][nx] != -1){
             visited[y][x] += visited[ny][nx];
             continue;
         }
         dfs(ny, nx);
         visited[y][x] += visited[ny][nx];
     }
}


