#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end());
    int l, r, mid, cnt1, tmp;


    l = 0;
    r = citations[citations.size() - 1];
    while(l <= r){

        mid = (l + r) / 2;
        cnt1 = 0;
        for(int i = 0 ; i < citations.size(); i++){
            if(mid <= citations[i]) cnt1++;
        }
        if(mid <= cnt1){
            l = mid +1;
            tmp = mid;
        } 
        else r = mid - 1;
    }
    return tmp;
}