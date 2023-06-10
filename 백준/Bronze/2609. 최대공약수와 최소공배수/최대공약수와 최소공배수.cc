#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
int cnt;


int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	fastio;
	cin >> n >> k;
	cout << gcd(n, k) << '\n';
	cout << lcm(n, k) << '\n';
	
	return 0;
}