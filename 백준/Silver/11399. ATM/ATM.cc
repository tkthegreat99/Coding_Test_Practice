#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;


int n, tmp;
int psum[1000];
vector<int> v;


int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	psum[0] = 0;
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + v[i - 1];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += psum[i];
	}
	cout << sum << '\n';
}