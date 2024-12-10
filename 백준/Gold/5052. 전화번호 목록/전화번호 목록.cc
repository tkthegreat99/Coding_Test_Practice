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

int n, t;



void solution()
{
    

}


signed main() {

    fastio;
    
    cin >> t;
    while (t--)
    {
        int chk = 0;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++)
        {
            int len1 = v[i].size();
            int len2 = v[i + 1].size();
            int shorter = len1 < len2 ? len1 : len2;
            string tmp1 = v[i].substr(0, shorter);
            string tmp2 = v[i + 1].substr(0, shorter);
            if (tmp1 == tmp2)
            {
                cout << "NO" << '\n';
                chk = 1;
                break;
            }
        }
        if(!chk) cout << "YES" << '\n';
    }

    
}

