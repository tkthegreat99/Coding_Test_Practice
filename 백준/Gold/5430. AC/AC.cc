#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>
using namespace std;

/* Method Initialization */
void input();
void solve();

/* Variable Initialization */
int n, t;
string p;
string arr;
deque<int> tmp;

int main()
{
    fastio;
    solve();
    return 0;
}

void input(){}

void solve() {
    cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        bool check = false;
        cin >> p;
        cin >> n;
        cin >> arr;
        int sum = 0;
        int counting = 0;
        int isNormal = 1;
        if(!tmp.empty()) tmp.clear();




        for(int j =0 ; j < arr.size()-1; j++){
            if(!counting && !isdigit(arr[j]) && isdigit(arr[j + 1])){
                counting = 1;
                sum += (arr[j + 1] - '0');
            }
            else if(counting && isdigit(arr[j + 1])){
                sum = sum * 10 + (arr[j + 1] - '0');
            }
            else if(counting && !isdigit(arr[j + 1])){
                counting = 0;
                tmp.push_back(sum);
                sum = 0;
            }
        }


        for(int j = 0 ; j < p.size(); j++){
            if(p[j] == 'R'){
                if(isNormal) isNormal = 0;
                else isNormal = 1;
            }
            else{
                if(tmp.empty()){check = true;}
                else{
                    if(isNormal)
                        tmp.pop_front();
                    else tmp.pop_back();
                }
            }
        }
        if(check){ cout << "error" << '\n'; continue;}

        if(tmp.empty()){ cout << "[]" << '\n'; continue;}

        if(!check) {
            cout << '[';
            for (int j = 0; j < tmp.size(); j++) {
                if(isNormal){
                    if (j != tmp.size() - 1) {
                        cout << tmp[j] << ',';
                    }
                    else cout << tmp[j];
                }
                else{
                    if(j != tmp.size() - 1){
                        cout << tmp[tmp.size() - j - 1] << ',';
                    }
                    else cout << tmp[tmp.size() - j - 1];
                }
            }
            cout << ']' << '\n';
        }

    }
}





