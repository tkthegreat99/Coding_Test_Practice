#include <iostream>
#include <cstring>
using namespace std;
char c[101][101];
int ans[101][101];
int main() {
    int h, w;
    cin >> h >> w;
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (c[i][j] == 'c')
            {
                ans[i][j] = 0;
            }
            else if (ans[i][j - 1] >= 0)
            {
                ans[i][j] = ans[i][j - 1] + 1;
            }
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
