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

int dp[10001];

signed main() {

    fastio;
    int n;

    cin >> n;

    fill(dp, dp + 10001, 1);
    
    for (int i = 2; i < 10001; i++)
    {
        dp[i] += dp[i - 2];
    }
    for (int i = 3; i < 10001; i++)
    {
        dp[i] += dp[i - 3];
    }

    while (n--)
    {
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << '\n';;
    }

}



