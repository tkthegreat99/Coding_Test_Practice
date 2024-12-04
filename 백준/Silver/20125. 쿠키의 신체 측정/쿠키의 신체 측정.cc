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
#define INF 987654321

using namespace std;

char a[1001][1001];
int n;

signed main() {

    fastio;

    cin >> n;

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int head = 0;
    pair<int, int> cor_heart;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '*' && head == 0)
            {
                head = 1;
                cout << i + 2 << " " << j + 1 << '\n';
                cor_heart = { i + 2, j + 1 };
                break;
            }
        }
    }

    cor_heart.first -= 1;
    cor_heart.second -= 1;

    //left arm

    int cnt = 0;
    for (int j = cor_heart.second - 1; j >= 0; j--)
    {
        if (a[cor_heart.first][j] == '*') cnt++;
        else break;
    }
    cout << cnt << " ";

    //right arm

    cnt = 0;
    for (int j = cor_heart.second + 1; j < n; j++)
    {
        if (a[cor_heart.first][j] == '*') cnt++;
        else break;
    }
    cout << cnt << " ";

    pair<int, int> butt;
    //hurry
    cnt = 0;
    for (int i = cor_heart.first + 1; i < n; i++)
    {
        if (a[i][cor_heart.second] == '*') cnt++;
        else
        {
            butt = { i, cor_heart.second };
            break;
        }
    }
    cout << cnt << " ";


    cnt = 0;
    for (int i = butt.first; i < n; i++)
    {
        if (a[i][butt.second - 1] == '*') cnt++;
        else break;
    }
    cout << cnt << " ";

    cnt = 0;
    for (int i = butt.first; i < n; i++)

    {
        if (a[i][butt.second + 1] == '*') cnt++;
        else break;
    }
    cout << cnt << " ";



}



