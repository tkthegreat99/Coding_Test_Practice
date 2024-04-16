#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

using namespace std;

int n;
int d[1000005];


int main(){
    fastio;
    cin >> n;
    d[1] = 0;
    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + 1;
        if(i % 2 == 0) d[i] = min(d[i], d[i/2] + 1);
        if(i % 3 == 0) d[i] = min(d[i], d[i/3] + 1);
    }
    cout << d[n];
}