#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;

/* Method Initialization */
void input();
void solve();
int check(string num);

/* Variable Initialization */
string n;
int m, b, res;
int button[10];


int main()
{
    fastio;
    input();
    solve();
    return 0;
}

void input(){
    cin >> n;
    cin >> m;
    for(int i = 0 ; i < m; i++){
        cin >> b;
        button[b] = 1;
    }
}

void solve() {
    if (stoi(n) == 100){
        cout << 0 << '\n';
        return;
    }

    int from_100;
    from_100 = abs(stoi(n) - 100);
    int cnt = 0;
    string up = n;
    string down = n;
    while(1){
        if(cnt + up.size() > from_100){
            cnt = from_100;
            break;
        }
        if(check(down) && stoi(down) >= 0){
            cnt += down.size();
            break;
        }
        else if (check(up)){
            cnt += up.size();
            break;
        }
        up = to_string(stoi(up) + 1);
        down = to_string(stoi(down) - 1);
        cnt++;
    }
    cout << cnt << '\n';
}

int check(string num){
    for(int i = 0 ; i < num.size(); i++){
        if(button[num[i] - '0']) return 0;
    }
    return 1;
}


