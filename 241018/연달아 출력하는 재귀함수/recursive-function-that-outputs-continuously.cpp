#include <iostream>
using namespace std;
#include <stack>

int main() {
    
    int n;
    cin >> n;
    stack<int> st;
    

    int cur = n;
    st.push(cur);
    while(cur >= 3)
    {
        cur = cur / 3;
        st.push(cur);
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}