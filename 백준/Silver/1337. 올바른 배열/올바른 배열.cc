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

int n;



signed main()
{
    fastio;
    set<int> s;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        s.insert(tmp);
    }
    int mx = -1;

    for (int i = 0; i < n; i++)
    {
        int std = v[i];
        int cnt = 0;
        for (int j = 0; j < 5; j++)
        {
            //set<int>::iterator iter;
            //iter = s.find(std + j);
            
            if (s.find(std+ j) != s.end()) //찾음
            {
                cnt++;
            }
        }
        mx = max(mx, cnt);
    }
    
    cout << 5 - mx;
    

}



