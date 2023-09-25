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
void dfs(int here, int depth);

/* Variable Initialization */
int n, m;
int arr[9];



int main()
{
    fastio;
    solve();
    return 0;
}

void input(){}

void solve() {
    cin >> n >> m;
    dfs(1, 0);
}

void dfs(int here, int depth){
    if (depth == m){
        for(int x : arr){
            if(x != 0) cout << x << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = here ; i <= n ; i++){
        arr[depth] = i;
        dfs(i, depth + 1);
    }
}


