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

int n, k;
int up = 0;
int down;

vector<int> robot;
vector<int> v;

void roll()
{

    up = up == 0 ? (2 * n) - 1 : up - 1;
    down = down == 0 ? (2 * n) - 1 : down - 1;

    if (robot[down]) robot[down] = 0;

}

void move()
{
    int cnt = n;
    int cur = down;
    while (cnt--)
    {
        cur = cur == 0 ? (2 * n) - 1 : cur - 1;
        if (robot[cur])
        {   
            if (robot[(cur + 1) % (2 * n)]) continue;
            if (v[(cur + 1) % (2 * n)] < 1) continue;
            robot[(cur + 1) % (2 * n)] = 1;
            robot[cur] = 0;
            if ((cur + 1) % (2 * n) == down) robot[down] = 0;
            v[(cur + 1) % (2 * n)] -= 1;
        }
    }
   

}


void upin()
{
    if (v[up] <= 0) return;
    v[up] -= 1;
    robot[up] = 1;
}

int check()
{
    int tmp = 0;
    for (int i : v)
    {
        if (i <= 0) tmp++;
        if (tmp >= k) return 1;
    }
    return 0;
}

signed main() {

    fastio;
    int answer = 0;
    cin >> n >> k;
    down = n -1;
    for (int i = 0; i < 2 * n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        robot.push_back(0);
    }

    while (1)
    {
        answer++;
        roll();

        move();

        upin();

        int flag = check();
        if (flag) break;
        
    }

    cout << answer << '\n';
    

}



