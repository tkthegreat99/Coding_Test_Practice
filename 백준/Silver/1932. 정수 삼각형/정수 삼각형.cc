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
void dfs(int y, int x);

/* Variable Initialization */
int n, m;
int a[504][504];

int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input(){
    cin >> n;
    fill(&a[0][0], &a[0][0] + 504 * 504, -1);
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> a[i][j];
        }
    }

    if(n == 1){ cout << a[0][0] << '\n'; return;}
    for(int i = 1 ; i < n; i++){
        for(int j = 0 ; j <= i; j++){
            if(j == 0) a[i][j] += a[i-1][j];
            else if(j == i) a[i][j] += a[i-1][j-1];
            else{
                int mx = max(a[i-1][j-1],a[i-1][j]);
                a[i][j] += mx;
            }
        }
    }
    int mx = -1e9;
    for(int i = 0; i < n; i++){
        mx = max(a[n-1][i], mx);
    }
    cout << mx << '\n';
}

void solve() {

}





