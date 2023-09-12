#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
using namespace std;

/* Method Initialization */
void combi(int start, vector<int> b);
int compare(string str1, string str2, string str3);
/* Variable Initialization */
int n, t;
string str;
vector<string> mbtis;
int mn;
map<string, int> m;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        mbtis.clear();
        m.clear();
        mn = 1e7;
        cin >> t;
        for(int j = 0; j < t ; j++)
        {
            cin >> str;
            m[str]++;
            mbtis.push_back(str);
        }
        if (t > 32){
            cout << 0 << '\n';
            continue;
        }
        if(m[str] == 3){
            cout << 0 << '\n';
            continue;
        }
        vector<int> b;
        combi(-1, b);
        cout << mn << '\n';
    }
    return 0;
}

void combi(int start, vector<int> b)
{
    int tmp;
    if(b.size() == 3)
    {
        tmp = compare(mbtis[b[0]], mbtis[b[1]], mbtis[b[2]]);
        mn = min(tmp, mn);
        return;
    }
    for(int i = start + 1; i < mbtis.size(); i++)
    {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int compare(string str1, string str2, string str3)
{
    int tmp = 0;
    for(int i = 0; i < 4; i++)
    {
        if(str1[i] != str2[i]) tmp++;
        if(str1[i] != str3[i]) tmp++;
        if(str2[i] != str3[i]) tmp++;
    }
    return tmp;
}


