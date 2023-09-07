#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

/* Initialize */
int N, num, cnt, res, mx = -1e9, mn = 1e9;
vector<int> numbers;
vector<string> signs;
string str_signs;

/* Used Methods */
void input();
void solve();
void combi(string comb, string others);
int main()
{
    fastio;
    input();
    solve();
}

void input()
{
    cin >> N;
    for(int i =0 ; i < N; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }
    for(int i = 0 ; i < 4; i++)
    {
        cin >> num;
        for(int j = 0 ; j < num; j++){
            cnt++;
            switch (i) {
                case 0:
                    str_signs += "+";
                    break;
                case 1:
                    str_signs += "-";
                    break;
                case 2:
                    str_signs += "*";
                    break;
                case 3:
                    str_signs += "/";
                    break;
            }
        }
    }
}
/* + - * / */
void solve()
{
    combi("", str_signs);
    for(int i = 0 ; i < signs.size(); i++)
    {
        res = numbers[0];
        for(int j = 0; j < N-1; j++)
        {
            if (signs[i][j] == '+') res += numbers[j+1];
            else if (signs[i][j] == '-') res -= numbers[j+1];
            else if (signs[i][j] == '*') res *= numbers[j+1];
            else res /= numbers[j+1];
        }
        mx = max(mx, res);
        mn = min(mn, res);
    }
    cout << mx << '\n';
    cout << mn << '\n';
}


void combi(string comb, string others) {
    if(comb != "" && comb.size() == cnt)
    {
        signs.push_back(comb);
        return;
    }
    for(int i =0 ; i < others.size(); i++)
        combi(comb + others[i], others.substr(0, i) + others.substr(i + 1));
}
