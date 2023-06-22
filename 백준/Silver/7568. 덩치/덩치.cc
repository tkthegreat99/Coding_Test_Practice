#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
#define MAX 1000000

int n, m;
pair<int, int> p[50];



void input();
void solve();
int main() {
    fastio;
    input();
    //solve();
    return 0;
}
void input(){
   cin >> n;
   int rank = 1;
   for(int i = 0 ; i < n; i++){
       cin >> p[i].first >> p[i].second;
   }
   for(int i = 0 ; i < n; i++){
       for(int j = 0 ; j < n; j++){
           if(p[i].first < p[j].first && p[i].second < p[j].second) rank++;
       }
       cout << rank << ' ';
       rank = 1;
   }
}

void solve(){

}
