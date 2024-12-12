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

int n, m, k;
int parents[500001];
int pnum[201];

int Find(int x)
{
    if (parents[x] == x) return x;
    return parents[x] = Find(parents[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    else if (x < y) parents[y] = x;
    else parents[x] = y;
}
signed main() {

    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }

    int num1, num2;
    int cnt = 0;
    int answer;
    bool check = true;
    for (int i = 0; i < m; i++)
    {
        cnt++;
        cin >> num1 >> num2;
        if (Find(num1) == Find(num2))
        {
            answer = cnt;
            check = false;
            break;
        }
        Union(num1, num2);
    }

    if (check)cout << 0 << '\n';
    else cout << answer << '\n';
    
    
}

