#include <iostream>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


typedef unsigned int ui;
ui ans;
ui list[10000];
ui k, n;

void input();
void solve();

int main(){
    fastio;
    solve();
    return 0;
}

void solve(){
    cin >> k >> n;
    ui maxi = 0;

    for(int i = 0 ; i < k ; i++){
        cin >> list[i];
        maxi = max(maxi, list[i]);
    }
    
    ui left = 1, right = maxi, mid;
    
    while(left <= right){
        
        mid = (left + right) / 2;
        
        ui now = 0;
        
        for(int i = 0 ; i < k ; i++) now += list[i] / mid;
        
        if(now >= n){
            left = mid + 1;
            ans = max(ans, mid);
        }
        else right = mid - 1;
    }
    cout << ans << '\n';
}
