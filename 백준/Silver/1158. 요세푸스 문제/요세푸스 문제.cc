#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <tuple>
#include <limits.h>
#define int long long
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n, k;
//deque<int> dq;
int flag[5001];
int tmp, chk;
int i = 1;



signed main() {
	fastio;

	cin >> n >> k;

	cout << "<";
	while (1) {
		//cout << "i : " << i << '\n';
		
		if (flag[i] == 0) {
			tmp++;
			if (tmp == k) {
				flag[i] = 1;
				chk++;
				tmp = 0;
				if (chk == n) {
					cout << i << ">";
					return 0;
				}
				else
				{
					cout << i << ", ";
				}
				
			}
		}
		i++;
		if (i == n + 1) i = 1;	
		
	}


	return 0;
}