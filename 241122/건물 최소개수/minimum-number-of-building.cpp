#include <iostream>
#include <stack>
using namespace std;


int shadow[50001];
int main() {
    
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        int x , h;
        cin >> x >> h;
        shadow[i] = h;
    }

    stack<int> stk;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int now = shadow[i];
       
        while(!stk.empty() && stk.top() > now)
        {
            if(stk.top())
            {
                cnt++;
                //cout << stk.top() << '\n';
            } 
            stk.pop();
        }
        
        if(!stk.empty() && stk.top() == now) continue;
        stk.push(now);
    }

    while(stk.size())
    {
        if(stk.top()) 
        {
            cnt++;
      //      cout << stk.top() << '\n';
        }
        stk.pop();
    }
    cout << cnt << '\n';


    return 0;
}