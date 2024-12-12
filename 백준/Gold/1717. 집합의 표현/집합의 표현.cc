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
int parents[1000001];

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

    for (int i = 0; i <= n; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int tmp;
        int num1, num2;
        cin >> tmp;
        if (tmp == 0)
        {
            
            cin >> num1 >> num2;
            Union(num1, num2);
        }
        else
        {
            cin >> num1 >> num2;
            if (Find(num1) == Find(num2))
            {
                cout << "YES" << '\n';
            }
            else cout << "NO" << '\n';
               
        }
    }
    
}

