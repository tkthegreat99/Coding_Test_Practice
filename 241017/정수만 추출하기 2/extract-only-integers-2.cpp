#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int CreateNum(string str)
{
    string tmp = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            tmp += str[i];
        }
    }
   // cout << tmp << " ";
    return stoi(tmp);
}

int main() {
    
    string str1;
    string str2;

    cin >> str1 >> str2;
    
    int tot = CreateNum(str1) + CreateNum(str2);

    cout << tot;






    return 0;
}