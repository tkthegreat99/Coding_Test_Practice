#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    char c;
    int T, k, n;
    cin >> T;
    while(T--){
        cin >> k;
        multiset<int> q;
        for (int i = 0; i < k;i++){
            cin >> c >> n;
            if(c =='I'){
                q.insert(n); 
            }else if(c == 'D'){
                if(q.empty()){
                    continue;
                }else if(n == 1){ 
                    auto iter = q.end(); 
                    iter--; 
                    q.erase(iter); 
                }else if(n == -1){
                    q.erase(q.begin()); 
                }
            }
        }
        if(q.empty()){
            cout << "EMPTY" << '\n';
        }else {
            auto iter = q.end();
            iter--;
            cout << *iter << " " << *q.begin() << '\n';
        }
    }
    return 0;
}
