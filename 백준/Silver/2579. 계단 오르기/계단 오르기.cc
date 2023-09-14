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

/* Variable Initialization */
int n, mx;
int dp[304];
int a[304];


int main()
{
    fastio;
    //input();
    solve();
    return 0;
}

void input(){}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i-2] + a[i], dp[i-3] + a[i-1] + a[i]);
    }
    cout << dp[n] << '\n';
}




