#include<iostream>
#include<queue>


using namespace std;

queue<int> q;

int n;
string s;
int tmp;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;



	while (n--) {
		cin >> s;
		if (s == "push") {
			cin >> tmp;
			q.push(tmp);
		}
		else if (s == "front") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.front() << '\n';
		}
		else if (s == "back") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			cout << q.back() << '\n';
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "pop") {
			if (q.empty()) { cout << -1 << '\n'; continue; }
			tmp = q.front();
			q.pop();
			cout << tmp << '\n';
		}
	}
	return 0;


}