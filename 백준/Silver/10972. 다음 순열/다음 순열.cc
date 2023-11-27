#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


/*Variable*/
int n, tmp, cnt;
vector<int> b;

int main(){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        b.push_back(tmp);
    }
    int k = next_permutation(b.begin(), b.end());
    if(k){
        for(int i : b) cout << i << " ";
    }
    else cout << -1 << '\n';

}

