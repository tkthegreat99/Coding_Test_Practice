
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int a[25][25];
int visited[25][25];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };


int n, m, k, tmp, tmp2;
int cnt, ret;
vector<int> v;

int dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n ) continue;
        if (!visited[ny][nx] && a[ny][nx] == 1) { 
            dfs(ny, nx); 
            ret++;
        }
    }   
    return ret;
}

//dfs를 시행한 횟수만큼 cnt를 해주자. 그니까 먼저
//

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            a[i][j] = s[j] - '0';
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                ret = 1;
                v.push_back(dfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for (int k : v) {
        cout << k << '\n';
    }

    
}
