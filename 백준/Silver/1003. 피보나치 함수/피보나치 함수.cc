#include <vector>
#include <iostream>
#include <set>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;

/* Initialize Methods*/
void input();
void print();

/* Initialize Variables*/
vector<pair<int, int>> v;
int t, n;

int main()
{
    fastio;
    v.push_back({1, 0});
    v.push_back({0, 1});
    v.push_back({1, 1});
    cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        cin >> n;

        if(v.size() - 1 < n )
        {
            for(int j = v.size(); j <= n; j++)
            {
                v.push_back({v[j-2].first + v[j-1].first, v[j-2].second + v[j-1].second});
            }
        }
        cout << v[n].first << " " << v[n].second << '\n';
    }
}


