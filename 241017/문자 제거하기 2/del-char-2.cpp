#include <iostream>
#include <algorithm>
#include <string>
#define fastio cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false)
using namespace std;

int main() {

    fastio;

    string str;
    int n;

    cin >> str >> n;
    int len = str.size();
    int tmp;
    string tmpstr = str;
    for(int i = 0 ; i < n; i++)
    {
        cin >> tmp;
        //cout << "tmp : " << tmp << '\n';
        if(tmp > len) continue;
        if(tmp == 1) tmpstr = tmpstr.substr(1);
        else if (tmp == len) tmpstr = tmpstr.substr(0, len - 1);
        else
        {
            tmpstr = tmpstr.substr(0, tmp-1) + tmpstr.substr(tmp);
        }
        cout << tmpstr << '\n';
        len = tmpstr.size();

    }


    
    return 0;
}
// 문자열의 길이를 매 번 측정. 
//