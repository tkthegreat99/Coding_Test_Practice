#include <vector>
#include <iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;

/* Initialize Methods*/
void input();

/* Initialize Variables*/
int n, m, k, l;
int psum[100001];
int num[100000];



int main()
{
    fastio;
    input();
}

void input()
{
    cin >> n >> m;
    for(int i = 0 ; i < n; i++) cin >> num[i];
    psum[0] = 0;
    for(int i = 1 ; i <= n; i++) psum[i] = psum[i-1] + num[i-1];
    for(int i = 0 ; i < m; i++) {
        cin >> k >> l;
        if (k == l) {
            cout << num[k - 1] << '\n';
            continue;
        }
        cout << psum[l] - psum[k - 1] << '\n';
    }
}