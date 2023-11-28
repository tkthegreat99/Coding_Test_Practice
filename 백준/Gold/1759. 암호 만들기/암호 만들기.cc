#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;


/*Variable*/
int l, c;
vector<char> v;
vector<char> v2;
char ch;

/*Method*/
int check(vector<char> a);
void dfs(int depth);

int main(){
    fastio;
    cin >> l >> c;
    for(int i = 0 ; i < c; i++){
        cin >> ch;
        v.push_back(ch);
    }
    sort(v.begin(), v.end());
    dfs(0);
}

void dfs(int depth){

        if(v2.size() == l){
            if(check(v2)){
                for(int i = 0 ; i < l; i++){
                    cout << v2[i];
                }
                cout << '\n';
            }
            return;
        }
        for(int i = depth; i < c; i++){
            v2.push_back(v[i]);
            dfs(i + 1);
            v2.pop_back();
        }
        return;
}

int check(vector<char> a){
    int mo = 0;
    int ja = 0;
    for(char ch : a){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            mo++;
        }
        else ja++;
    }
    if(mo>=1 && ja >=2) return 1;
    else return 0;
}