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

bool cmp(int a, int b)
{
    if (a > b) return 1;
    return 0;
}


signed main() {

    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer += a[i] * b[i];
    }
    
    cout << answer << '\n';
   

    
    // 0 1 1 1 6 
    // 8 7 3 2 1


}



