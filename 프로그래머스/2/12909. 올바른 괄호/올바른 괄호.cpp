#include <string>
#include <iostream>
#include <stack>

using namespace std;

stack<int> st;


bool solution(string s)
{
   bool answer;
    
    if(s.size() % 2 == 1) return false;
    
    for(int i = 0 ; i < s.size(); i++)
    {   
        
        if(s[i] == ')')
        {
            if(!st.empty())
            {
                if(st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        else 
        {
            st.push(s[i]);
        }
    }
    
   
    return st.empty();
}