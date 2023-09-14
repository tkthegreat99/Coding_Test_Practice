#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;

/* Method Initialization */
void input();
void solve();

/* Variable Initialization */
int n, m, res;
string str;


int main()
{
    fastio;
    //input();
    solve();
    return 0;
}

void input()
{

}

void solve()
{
    cin >> n;
    cin >> m;
    cin >> str;
    string pn = "I";
    for(int i = 0 ; i < n; i++){
        pn += "OI";
    }
    int len = pn.size();
    for(int i = 0 ; i < m - 2*n; i++){
        if(pn == str.substr(i, len)){
            res++;
        }
    }
    cout << res << '\n';
}




