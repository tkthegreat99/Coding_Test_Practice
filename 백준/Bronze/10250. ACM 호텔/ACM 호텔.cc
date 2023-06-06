#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


int t;
int h, w, n;


int main() {

    cin >> t;
    while (t--) {
        cin >> h >> w >> n;

        int tmp;
        if (n % h == 0) tmp = h;
        else tmp = n % h;

        int tmp2;
        if (n % h == 0) tmp2 = n / h;
        else tmp2 = n / h + 1;




        cout << tmp * 100 + tmp2 << '\n';


    }


}




    