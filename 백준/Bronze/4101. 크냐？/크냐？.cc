#include<iostream>
using namespace std;

int n , m;
int main(){
    while(true){
    cin >> n >> m;
        if(n == 0 && m == 0) break;
    if(n > m){
        cout << "Yes" << '\n';
    }
        else cout << "No" << '\n';
    }
    return 0;
}