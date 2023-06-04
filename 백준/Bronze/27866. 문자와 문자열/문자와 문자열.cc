#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;


string str;
int n;

int main() {
	fastio;
	cin >> str;
	cin >> n;
	cout << str[n-1] << '\n';
	
}