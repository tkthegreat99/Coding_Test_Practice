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

map<int, int> m;

signed main() {

    fastio;
    int x, n;
    cin >> x >> n;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }


    if (*max_element(v.begin(), v.end()) == 0)
    {
        cout << "SAD" << '\n';
        return 0;
    }
    int mx = -1;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += v[i];
    }
    int cnt = 0;
    mx = max(mx, tmp);
    m[mx]++;
    for (int i = n; i < x; i++)
    {
        tmp -= v[i - n];
        tmp += v[i];
        mx = max(mx, tmp);
        m[tmp]++;
        
    }
    
    cout << mx << '\n';
    cout << m[mx] << '\n';

}



