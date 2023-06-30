#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string a;
    int cnt=0;
    cin >> a;
    stack<int> s;
        for (int i=0; i < a.size(); i++) {
            if (a[i] == '(')
                s.push(i);
            else {
                if (s.top()+1 == i) {
                	s.pop();
                   	cnt+=s.size();
                }
                else {
                	s.pop();
                	cnt++;
                }
            }
        }
    cout << cnt << '\n';
}