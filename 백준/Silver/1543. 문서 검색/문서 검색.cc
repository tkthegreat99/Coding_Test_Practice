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

using namespace std;

signed main()
{
    fastio;
    int answer = 0;
    string str;

    string target;

    getline(cin, str);
    getline(cin, target);
    int len = target.length();

    if (str.length() < target.length())
    {
        cout << 0;
        return 0;
    }

    int k;
    while (( k = str.find(target)) != string::npos)
    {
        str.erase(0, k + len);
        //str = str.substr(k + len);
        answer++;
        
    }
    cout << answer << '\n';
}
