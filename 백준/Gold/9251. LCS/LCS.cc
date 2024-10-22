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

using namespace std;
int n;

int dp[1002][1002];
int mx(int a, int b) {
    return a > b ? a : b;
}
signed main()
{
	fastio;
	
    string s1;
    string s2;
    cin >> s1 >> s2;
    dp[0][0] = 0;
    for (int i = 0; i <= s1.length(); i++) {
        dp[i][0] = 0;
    } for (int i = 0; i <= s2.length(); i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // 문자열이 같아 lcs하나 늘려줌
            }
            else
            {
                dp[i][j] = mx(dp[i][j - 1], dp[i - 1][j]);
                //둘 중 더 큰 거 선택
            }
        }
    }
    cout << dp[s1.length()][s2.length()];
}