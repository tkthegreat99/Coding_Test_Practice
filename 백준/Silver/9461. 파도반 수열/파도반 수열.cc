#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;

/* Method Initialization */
void input();
void solve();

/* Variable Initializati1on */
int n, t, mx = -1e9;
long long dp[102];


int main()
{
    fastio;
    //input();
    solve();
    return 0;
}

void input()
{
}

void solve()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    cin >> t;

    for(int i = 0 ; i < t; i++) {
        cin >> n;

        if (n <= 3){
            cout << 1 << '\n';
            continue;
        }
        else {
            if (dp[n] != 0) {
                cout << dp[n] << '\n';
                continue;
            }
            for (int j = 4; j <= n; j++) {
                dp[j] = dp[j - 2] + dp[j - 3];
            }
            cout << dp[n] << '\n';
        }
    }
}



