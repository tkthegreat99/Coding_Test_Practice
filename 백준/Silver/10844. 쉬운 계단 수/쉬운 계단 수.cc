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


int dp[105][10];


signed main() {

    fastio;
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) dp[i][j] = dp[i - 1][1];
            else if (j == 9) dp[i][j] = dp[i - 1][8];
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] = dp[i][j] % 1000000000;

        }
    }

    int answer = 0;
    for (int i = 0; i <= 9; i++) answer += dp[n][i];
    answer %= 1000000000;
    cout << answer << '\n';

}



