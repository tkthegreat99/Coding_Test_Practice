#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <limits.h>
#include <math.h>
#include <deque>
#include <sstream>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)
#define INF 987654321

using namespace std;

int visited[51][51];
char a[51][51];


signed main() {

    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && a[i][j] == '|')
            {
                visited[i][j] = 1;
                answer++;
                int ny = i;
                while (1)
                {
                    ny++;
                    if (ny == n) break;
                    if (a[ny][j] == '-') break;
                    visited[ny][j] = 1;
                }
                
            }
            if (!visited[i][j] && a[i][j] == '-')
            {
                visited[i][j] = 1;
                answer++;
                int nx = j;
                while (1)
                {
                    nx++;
                    if (nx == m) break;
                    if (a[i][nx] == '|') break;
                    visited[i][nx] = 1;
                }
            }

        }
    }

    cout << answer << '\n';
}



