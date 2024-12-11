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
int parents[51];
vector<int> know;
vector<vector<int>> v(50);

int Find(int x)
{
    if (parents[x] == x) return x;
    return x = Find(parents[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parents[x] = y;
}



signed main() {

    fastio;
    cin >> n >> m >> k;

    while (k--)
    {
        int t;
        cin >> t;
        know.push_back(t);
    }
    for (int i = 1; i <= n; i++) parents[i] = i;

    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        int num;
        int prev;
        for (int j = 0; j < p; j++)
        {
            if (j >= 1)
            {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else
            {
                cin >> num;
            }
            v[i].push_back(num);
        }
    }

    for (auto& list : v)
    {
        bool flag = false;
        for (auto& person : list)
        {
            if (flag) break;
            for (auto& t : know)
            {
                if (Find(person) == Find(t))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) m--;
    }
    cout << m;
}

