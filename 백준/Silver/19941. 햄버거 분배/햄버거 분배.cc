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
int cnt = 0;
char c;
vector<char> ph;

signed main() {

    fastio;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        ph.push_back(c);
    }

    for (int i = 0; i < n; i++)
    {
        if (ph[i] != 'P') continue;
        for (int j = i - k; j <= i + k; j++)
        {
            if (0 <= j && j < n && ph[j] == 'H')
            {
                ph[j] = '0';
                cnt++;
                break;
            }
        }
    }
    
        
    cout << cnt << '\n';

}

