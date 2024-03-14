#include <string>
#include <vector>
#include <map>

using namespace std;

int answer;


map<string, int> mp;

int check(vector<string> want, vector<int> number, map<string, int> mp){
    int chk = 1;
    for(int i = 0; i < want.size(); i++){
        if(mp[want[i]] != number[i]) chk = 0;
    }
    return chk;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    int amount = 0;
    for(int i = 0 ; i < number.size(); i++) amount += number[i];
    for(int i = 0 ; i < discount.size() - amount + 1; i++){
        mp.clear();
        for(int j = i; j < amount + i; j++){
            mp[discount[j]]++;
        }
        //for(pair<string, int> i : mp) cout << i.first << " : " << i.second << '\n';
        //cout << i << "time : " << "==========================\n";
        if(check(want, number, mp)){
            answer++;
            //cout << "OK" << '\n';
        }
    }


    return answer;
}
