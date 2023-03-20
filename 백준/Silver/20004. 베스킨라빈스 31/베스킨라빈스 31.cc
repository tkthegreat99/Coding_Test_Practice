#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int gap;
	int a;
	cin >> a;

	for (int i = 1; i < a + 1; i++) {
		gap = i + 1;

		if (30 % gap == 0) cout << i << '\n';
	}

}