#include <string>
#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

bool solution(string s)
{
    int len = s.size();
    for(int i = 0 ; i < len; i++)
    {
        if(!st.empty() && s[i] == ')' && st.top() == '(')
            st.pop();
        else st.push(s[i]);
    }
    
    
    
    return st.empty();
}