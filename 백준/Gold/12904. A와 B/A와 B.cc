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


string s;
string t;

signed main() {

    fastio;
    
    cin >> s;
    cin >> t;

    while (1)
    {
        if (t[t.size() - 1] == 'A')
        {
            t.pop_back();
        }
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        if (t.size() == s.size())
        {
            if (t == s) cout << 1;
            else cout << 0;
            break;
        }
    }

}

