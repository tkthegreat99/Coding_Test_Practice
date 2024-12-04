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

int dp[16];

signed main() {


    int n;
    int answer = 0;
    cin >> n;

    //dp[n] = n 일차에 받을 수 있는 최대 금액

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int t, p;
        cin >> t >> p;
        v[i].first = t;
        v[i].second = p;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + v[i- 1].first - 1 > n) continue;
        dp[i + v[i - 1].first - 1] = max(dp[i + v[i - 1].first - 1], dp[i - 1] + v[i - 1].second);
        answer = max(answer, dp[i + v[i - 1].first - 1]);
    }

    cout << answer << '\n';
    fastio;

}



