#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <limits.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;


int n, m;
int visited[9];
int arr[9];

void dfs(int cnt)
{
   // cout << "new dfs started : cnt = " << cnt << '\n';
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';

        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            //cout << "visited[" << i << "] = true" << '\n';
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
          //  cout << "visited[" << i << "] = false" << '\n';
        }
    }
}


void print(vector<int> v) {
    for (int x : v) cout << x << " ";
    cout << '\n';
}


signed main() {
    fastio;

    cin >> n >> m;

    dfs(0);

  
}


