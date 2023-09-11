#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;

/* Initialize Methods*/
void input();
void print();

/* Initialize Variables*/
priority_queue<int> q;
int x, n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        cin >> x;
        if ( x > 0) q.push(x);
        if (q.empty() && x == 0){
            cout << 0 << '\n';
            continue;
        }
        if ( x == 0) {
            cout << q.top() << '\n';
            q.pop();
        }
    }

}


