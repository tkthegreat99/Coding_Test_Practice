#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

/* Initialize */
int N, cnt;
int col[16];

/* Used Methods */
void input();
void solve();
void queen(int x);
bool check(int x);
int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input()
{
    cin >> N;
}
void solve()
{
    queen(0);
    cout << cnt;
}

void queen(int x)
{
    if(N == x) cnt++;
    else
    {
        for(int i = 0 ; i < N; i++) {
            col[x] = i;
            bool res = true;
            for(int j = 0 ; j < x; j++)
            {
                if (col[x] == col[j] || abs(col[x] - col[j]) == x - j){
                    res = false;
                    break;
                }
            }
            if (res) queen(x + 1);
        }
    }
}