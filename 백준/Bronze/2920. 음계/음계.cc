#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
    
bool cmp(int x, int y) {
    if (x > y) return true;
    else return false;
}


vector<int> v;
vector<int> gijun1;
vector<int> gijun2;
int n;

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> n;
        v.push_back(n);
    }

    gijun1 = v;
    gijun2 = v;
    sort(gijun1.begin(), gijun1.end());
    sort(gijun2.begin(), gijun2.end(), cmp);
    
  
    
    if (v == gijun1) {
        cout << "ascending" << '\n';
    }
    else if (v == gijun2) cout << "descending" << '\n';
    else cout << "mixed" << '\n';
    
    


}
