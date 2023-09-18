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
int n, x;
struct cmp
{
    bool operator()(int a, int b)
    {
        if(abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

int main()
{
    fastio;
    solve();
    return 0;
}

void input(){}

void solve() {
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for(int i = 0 ; i < n; i++)
    {
        cin >> x;
        if(pq.empty() && x == 0){
            cout << 0 << '\n';
        }

        else if (x == 0){
            cout << pq.top() << '\n';
            pq.pop();
        }
        else{
            pq.push(x);
        }
    }
}





