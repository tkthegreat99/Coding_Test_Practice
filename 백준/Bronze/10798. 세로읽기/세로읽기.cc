#include <iostream>
#include <string>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

 

string word[5];
void input();
void solve();

 

int main(void)

{
    fastio;
    input();
    solve(); 
    return 0;

}

void input(){
    for (int i = 0; i < 5; i++) cin >> word[i];
}

void solve(){
    for (int i = 0; i < 15; i++) 
                 for (int j = 0; j < 5; j++)
                         if (i < word[j].size())
                                 cout << word[j][i];
        cout << endl;

}

