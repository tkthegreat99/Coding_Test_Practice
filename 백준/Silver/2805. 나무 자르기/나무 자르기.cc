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
int cal(int a, int b);
/* Variable Initialization */
int n;
long long m;
int tr;
int mx = -2e9;
long long sum;
long long a[1000004];


int main()
{
    fastio;
    solve();
    return 0;
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> tr;
        a[i] = tr;
        mx = max(tr, mx);
    }
    if (mx == m){
        cout << 0 << '\n';
        return;
    }
    int l = 1;
    int tmp = 0;
    int r = mx;
    int mid = mx/2;
    while(l <= r) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += cal(a[i], mid);
        }
        if (sum >= m) {
            l = mid + 1;
            tmp = max(mid, tmp);
            mid = (r + l) / 2;
        }
        else{
            r = mid - 1;
            mid = (r + l) / 2;
        }
    }
    cout << tmp << '\n';
}

int cal(int a, int b)
{
    int tmp;
    if (a - b < 0) return 0;
    return a - b;
}



