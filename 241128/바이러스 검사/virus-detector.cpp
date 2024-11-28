#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long n;
int main() {

    cin >> n;
    vector<long long> rest(n);
    for(long long i = 0 ; i < n; i++) cin >> rest[i];
    
    long long manager, worker;
    cin >> manager >> worker;

    long long cnt = 1;

    for(long long i = 0; i < n ; i++)
    {
        if(rest[i] <= manager) // 팀장 선에서 컷 할수 있는 경우
        {
            continue;
        }
        else // 만약에 팀장 선에서 해결 불가
        {
            long long left = rest[i] - manager;
            if(left % worker == 0) cnt +=  (left / worker);
            else cnt += (left / worker) + 1;
        }
    }


    cout << cnt << '\n';

    return 0;
}