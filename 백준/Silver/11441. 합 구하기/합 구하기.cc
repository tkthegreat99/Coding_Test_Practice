#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
using namespace std;

int n, m, tmp1, tmp2;
int tmp;
int psum[100004];
int a[100004];

int main(){
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> tmp1 >> tmp2;
        cout << psum[tmp2] - psum[tmp1 - 1] << '\n';
    }
}