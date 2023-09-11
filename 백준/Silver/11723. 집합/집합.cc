#include <vector>
#include <iostream>
#include <set>
#include <string>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;

/* Initialize Methods*/
void input();
void print();

/* Initialize Variables*/
int m;
set<int> s;
string order;
int option;
int arr[21];

int main()
{
    fastio;
    cin >> m;
    for(int i = 0 ; i < m; i++)
    {
        cin >> order;
        if (order == "add")
        {
            cin >> option;
            arr[option] = 1;
        }
        else if(order == "remove")
        {
            cin >> option;
            arr[option] = 0;
        }
        else if (order == "check")
        {
            cin >> option;
            if(arr[option]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (order == "toggle")
        {
            cin >> option;
            arr[option] = !arr[option];
        }
        else if (order == "all")
        {
            for(int &x : arr) x = 1;
        }
        else{
            for(int &x : arr) x = 0;
        }
    }
}


