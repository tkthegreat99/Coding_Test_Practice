#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;


int n, a[1000004], ret[1000004];
stack<int> s; // 짝짓기 문제 stack!!



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	

	cin >> n;
	memset(ret, -1, sizeof(ret)); // 다 -1로 초기화 해놓고
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (s.size() && a[s.top()] < a[i]) { // top에 있는 거 확인할 때 -> 항상 size먼저 체크하고 && .. 오큰수라면!
			ret[s.top()] = a[i]; s.pop(); 
		}
		s.push(i); 
	}
	for (int i = 0; i < n; i++) cout << ret[i] << " ";
	return 0;
}