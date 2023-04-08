#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


int c;
int tmp;


bool is_prime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	int sqrt_n = sqrt(n);
	for (int i = 3; i <= sqrt_n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}




vector<int> prime_until(int n) {
	vector<int> primes;
	for (int i = 0; i <= n; i++) {
		if (is_prime(i)) primes.push_back(i);
	}
	


	return primes;
}

bool is_possible(int n) {
	vector<int> primes = prime_until(n);
	for (int prime : primes) {
		if (is_prime(n - prime)) return true;
	}
	return false;
}



int main() {
	cin >> c;
	
	
	while (c--) {
		cin >> tmp;
		if (is_possible(tmp)) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	
	return 0;
}