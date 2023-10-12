#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

/* Method Initialization */
void input();
void solve();

/* Variable Initialization */
int n, ca1, ca2, ca3, tot;
int color[1001][3];
int dp[1001];


int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input(){}

void solve() {
    cin >> n;
    int cost[3];
    color[0][0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> cost[0] >> cost[1] >> cost[2];
        color[i][0] = min(color[i-1][1], color[i-1][2]) + cost[0];
        color[i][1] = min(color[i-1][0], color[i-1][2]) + cost[1];
        color[i][2] = min(color[i-1][1], color[i-1][0]) + cost[2];
    }
    cout << min(color[n][2], min(color[n][0], color[n][1]));
}






