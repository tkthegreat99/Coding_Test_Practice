#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int a,b,c;
    while(1)
    {
        int tot = 0;
        vector<int> v(3);
        for(int i = 0 ; i < 3; i++)
        {
            cin >> v[i];
            tot += v[i];
        }
        if(tot == 0) break;
        int mx = *max_element(v.begin(), v.end());
        
        if(mx >= tot - mx)
        {
            cout << "Invalid\n";
        }
        else
        {
            if(v[0] == v[1] && v[1] == v[2])
            {
                cout << "Equilateral\n";
            }
            else if((v[0] == v[1] && v[1] != v[2]) || (v[1] == v[2] && v[0] != v[1]) || (v[0] == v[2] && v[1] != v[2]))
            {
                cout << "Isosceles\n";
            }
            else cout << "Scalene\n";
        }
        
        
        
    }

    return 0;
}