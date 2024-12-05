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

int n, m;

int pos[100001];

signed main() {

    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> pos[i];

    int ans = INF;
    int l = 0;
    int r = 100000;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool iscan = true;

        if (pos[0] > mid) iscan = false;
        for (int i = 0; i < m - 1; i++)
        {
            if (pos[i + 1] - pos[i] > mid * 2)
            {
                iscan = false;
                break;
            }
        }

        if (n - pos[m - 1] > mid) iscan = false;

        if (!iscan) l = mid + 1;
        else
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}



