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
unordered_map<string, int> m;

signed main() {

    fastio;
    int n;
    char game;
    

    int players = 1;

    cin >> n >> game;
    if (game == 'Y') players = 2;
    else if (game == 'F') players = 3;
    else players = 4;


    string name;
    int cnt = 1;
    int gamecnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (!m[name])
        {
            //cout << "새로운 참가자 : " << name << '\n';
            m[name]++;
            cnt++;
            if (cnt == players)
            {
                cnt = 1;
                gamecnt++;
            }

        }
        else
        {
            //cout << "이미 게임 했던 참가자 : " << name << '\n';
            continue;
        }
    }

    cout << gamecnt << '\n';



    



}



