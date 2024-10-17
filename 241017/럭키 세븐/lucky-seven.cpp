#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    
    int n;
    int tmp;
    cin >> n;

    int cnt = 0, ret = 0;
    for(int i = 0 ; i < n; i++)
    {
        cin >> tmp;
        if(tmp % 7 == 0) 
        {
            cnt++;
            ret+=tmp;
        }
    }

    float average = float(ret) / float(cnt);
    average = round(average * 10) / 10;

    cout << cnt << " "<< ret << " "<< average;


    return 0;
}