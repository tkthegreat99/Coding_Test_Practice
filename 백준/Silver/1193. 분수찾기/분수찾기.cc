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

int n, m;


int pacto(int start, int end)
{
    int tmp = 1;
    for (int i = start; i <= end; i++)
    {
        tmp *= i;
    }
    return tmp;
}



signed main() {

    fastio;

    int line = 1;
    int x;
    cin >> x;

    while (x - line > 0)
    {
        x -= line;
        line++;
    }

    if (line % 2) cout << line + 1 - x << '/' << x;
    else cout << x << '/' << line + 1 - x;
}



