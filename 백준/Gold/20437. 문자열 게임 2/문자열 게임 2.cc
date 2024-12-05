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

int t;
map<int, int> m;
signed main() {

    fastio;
    cin >> t;
    
    
    while (t--)
    {
        string str;
        int k;
        cin >> str;
        cin >> k;
        vector<int> count(26);
        for (int i = 0; i < str.length(); i++)
        {
            ++count[str[i] - 'a'];
        }

        int answer3 = INF;
        int answer4 = -1;

        for (int i = 0; i < str.length(); i++)
        {
            if (count[str[i] - 'a'] < k) continue;

            int cnt = 0;

            for (int j = i; j < str.length(); j++)
            {
                if (str[i] == str[j]) cnt++;

                if (cnt == k)
                {
                    answer3 = min(answer3, j - i + 1);
                    answer4 = max(answer4, j - i + 1);
                    break;
                }
            }
        }

        if (answer3 == INF || answer4 == -1) cout << -1 << '\n';
        else cout << answer3 << " " << answer4 << '\n';
        
        
    }

}



