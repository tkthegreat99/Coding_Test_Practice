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
typedef long long ll;
ll a[2][100004];


int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input(){
    cin >> m;
    for(int i =0 ;i < m ; i++){
        cin >> n;
        fill(&a[0][0], &a[0][0] + 100004 * 2 , 0);
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < n; k++){
                cin >> a[j][k];
            }
        }
        if(n == 1){
            cout << max(a[0][0], a[1][0]) << '\n';
            continue;
        }
        if (n == 2){
            cout << max(a[0][0] + a[1][1], a[1][0] + a[0][1]) << '\n';
            continue;
        }
        else{
            a[0][1] += a[1][0];
            a[1][1] += a[0][0];

            for(int b = 2; b < n; b++){
                a[0][b] += max(a[1][b-1], a[1][b-2]);
                a[1][b] += max(a[0][b-1], a[0][b-2]);
            }
            cout << max(a[0][n-1], a[1][n-1]) << '\n';
        }
    }
}

void solve() {

}





