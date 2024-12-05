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

bool cmp(int a, int b)
{
    if (a > b) return 1;
    return 0;

}


signed main() {

    fastio;
    int answer = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int p;
        int l;
        cin >> p >> l;
        vector<int> tmpv(p);
        for (int j = 0; j < p; j++)
        {
            cin >> tmpv[j];
        }
        sort(tmpv.begin(), tmpv.end(), cmp);

        if (p < l)
        {
            v[i] = 1;
        }
        else
        {
            v[i] = tmpv[l - 1];
        }
    }

    sort(v.begin(), v.end());
    
    for (int i : v)
    {
        
        m -= i;
        answer++;
        if (m < 0)
        {
            answer--;
            break;
        }
    }
    cout << answer << '\n';

}



