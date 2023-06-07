#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


vector<int> v;
int n, tmp;
int isPrime(int n);

int main() {
    cin >> n;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (isPrime(v[i])) cnt++;
    }
    cout << cnt << '\n';

}

int isPrime(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}





    