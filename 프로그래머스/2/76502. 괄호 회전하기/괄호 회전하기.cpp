#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int answer;


void IsPossible(string s){
    stack<int> st;
    for(int i = 0; i < s.size(); i++){
        if(st.empty()) st.push(s[i]);
        else if(s[i] == ']' && st.top() == '[') st.pop();
        else if(s[i] == ')' && st.top() == '(') st.pop();
        else if(s[i] == '}' && st.top() == '{') st.pop();
        else st.push(s[i]);
    }
    //cout << st.size() << '\n';
    //cout << st.empty() << '\n';
    if(st.empty()) answer++;
}



int solution(string s) {

    int size = s.size();

    for(int i = 0 ; i < size; i++){
        IsPossible(s);
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    return answer;
}