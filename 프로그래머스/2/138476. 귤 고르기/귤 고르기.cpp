#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> ct;


int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end());
    
    for(int i = 0 ; i < tangerine.size(); ){
        int j = i + 1, cnt = 1;
        while(tangerine[i] == tangerine[j]){
            cnt++;
            j++;
        }
        ct.push_back(cnt);
        i = j;   
    }
    
    
    
    sort(ct.begin(), ct.end(), greater<int>());
    int tmp = 0;
    for(int i = 0; i < ct.size() ; i++){
        tmp += ct[i];
        if(tmp >= k) return i+1;
    }

}