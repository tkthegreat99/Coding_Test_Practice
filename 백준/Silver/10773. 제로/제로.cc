#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) v.pop_back();
		else v.push_back(num);
	}
	int sum = 0;
	for (auto a : v) sum += a;
	cout << sum << '\n';
    
    return 0;

}

